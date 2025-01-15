/*******************************************************************************
 * 文件名称: build
 * 项目名称: SilkCasket
 * 创建时间: 2025/1/15
 * 作者: EternalFuture゙
 * Github: https://github.com/2079541547
 * 版权声明: Copyright © 2024 EternalFuture. All rights reserved.
 * 许可证: Licensed under the Apache License, Version 2.0 (the "License");
 *         you may not use this file except in compliance with the License.
 *         You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0
 *
 *         Unless required by applicable law or agreed to in writing, software
 *         distributed under the License is distributed on an "AS IS" BASIS,
 *         WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *         See the License for the specific language governing permissions and
 *         limitations under the License.
 *
 * 描述信息: 本文件为Silk Casket项目中的一部分，允许在遵守Apache License 2.0的条件下自由用于商业用途。
 * 注意事项: 请严格遵守Apache License 2.0协议使用本代码。Apache License 2.0允许商业用途，无需额外授权。
 *******************************************************************************/

#include <build.hpp>
#include <map>
#include <fstream>
#include <compress.hpp>
#include <utils.hpp>
#include <encryption.hpp>

void SilkCasket::builder::configureEntries(const std::filesystem::path &Path,
                                           const std::string &parentRelativePath) {
    std::map<std::vector<uint8_t>, int> dataToIndexMap;

    for (const auto& _ : std::filesystem::directory_iterator(Path)) {
        std::string relativePath = parentRelativePath.empty() ? _.path().lexically_relative(Path).string() : (parentRelativePath + "/" + _.path().filename().string());

        if (is_directory(_)) {
            SilkCasket::FileStructure::entry e = {
                    relativePath,
                    is_regular_file(_),
                    0
            };
            entry.push_back(e);
            configureEntries(_.path(), relativePath);
        } else if (is_regular_file(_)) {
            std::ifstream file(_.path(), std::ios::binary);
            std::vector<uint8_t> Data((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
            file.close();

            auto it = dataToIndexMap.find(Data);
            int addressIndex;
            if (it != dataToIndexMap.end()) {
                addressIndex = it->second;
            } else {
                tempData.insert(tempData.end(), Data.begin(), Data.end());
                SilkCasket::FileStructure::address addr = {
                        (size_t)(tempData.size() - Data.size()) + 48,
                        (size_t)Data.size()
                };
                addressIndex = (int)data.Address.size();
                data.Address.push_back(addr);
                dataToIndexMap[Data] = addressIndex;
            }

            SilkCasket::FileStructure::entry e = {
                    relativePath,
                    true,
                    addressIndex
            };
            entry.push_back(e);
        }
    }
}

void SilkCasket::builder::build(const std::filesystem::path &Path, const std::filesystem::path &OutPath,
                                SilkCasket::MODE Mode, size_t blockSize, bool entryEncryption, const std::string &key) {
    auto cacheDir = Path.parent_path() / "cache";
    std::filesystem::create_directories(cacheDir); // 创建缓存目录

    // 遍历源目录中的文件并处理
    for (const auto &_ : std::filesystem::recursive_directory_iterator(Path))
    {
        if (_.is_regular_file())
        {
            auto relativePath = std::filesystem::relative(_.path(), Path);
            auto cacheFilePath = cacheDir / relativePath;

            std::filesystem::create_directories(cacheFilePath.parent_path());

            auto compressedData = SilkCasket::Compress::smartCompress(_.path(), Mode, blockSize);
            if (!compressedData.empty())
            {
                Utils::Vuint8ToFile(cacheFilePath, compressedData);

                if (entryEncryption)
                {
                    auto encryptionData = SilkCasket::encryptFile(key, compressedData);
                    if (!encryptionData.empty())
                    {
                        Utils::Vuint8ToFile(cacheFilePath, encryptionData);
                    }
                }
            }
        }
    }

    configureEntries(cacheDir);

    SilkCasket::Compress Compress;
    auto FileEntry = Compress.smartCompress(SilkCasket::FileStructure::serialize_entries(entry), Mode);
    auto FileEntryData = Compress.smartCompress(SilkCasket::FileStructure::data::serialize(data), Mode);

    header = {
            "SilkCasket",
            20250115,
            {(size_t)tempData.size() + 48, (size_t)FileEntry.size()},
            {(size_t)tempData.size() + (size_t)FileEntry.size() + 48, (size_t)FileEntryData.size()},
    };

    auto FileHeader = SilkCasket::FileStructure::header::serialize(header);

    Data.insert(Data.end(), FileHeader.begin(), FileHeader.end());
    Data.insert(Data.end(), tempData.begin(), tempData.end());

    Data.insert(Data.end(), FileEntry.begin(), FileEntry.end());
    Data.insert(Data.end(), FileEntryData.begin(), FileEntryData.end());

    SilkCasket::Utils::Vuint8ToFile(OutPath, Data);

    std::filesystem::remove_all(cacheDir);
}