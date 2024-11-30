/*******************************************************************************
 * 文件名称: build
 * 项目名称: SilkCasket
 * 创建时间: 2024/11/24
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
 * 描述信息: 本文件为SilkCasket项目中的一部分，允许在遵守Apache License 2.0的条件下自由用于商业用途。
 * 注意事项: 请严格遵守Apache License 2.0协议使用本代码。Apache License 2.0允许商业用途，无需额外授权。
 *******************************************************************************/

#include <build/builder.hpp>
#include <utils/file.hpp>
#include <compress/compress.hpp>
#include <encryption.hpp>
#include <cstring>
#include <log.hpp>
#include <future>
#include <vector>
#include <thread>


void SilkCasket::Build::Builder::Build::build(const filesystem::path& Path,
                                              const filesystem::path& OutPath,
                                              SilkCasket::Compress::Mode::MODE Mode,
                                              bool Encryption,
                                              const string& key
                                              ) {

    auto temp = Path.parent_path() / "temp";
    filesystem::remove_all(temp);

    SilkCasket::Utils::File::copyDirectory(Path, temp, 8096 * 1024);

    for (const auto& entry : filesystem::recursive_directory_iterator(temp)) {
        if (entry.is_regular_file()) {
            auto compressedData = SilkCasket::Compress::smartCompress(entry.path(), Mode);
            if (!compressedData.empty()) {
                Utils::File::Vuint8ToFile(entry.path(), compressedData);
            }
        }
    }

    if (Encryption)
    {
        vector<future<void>> futures;
        for (const auto &entry : filesystem::recursive_directory_iterator(temp))
        {
            if (entry.is_regular_file())
            {
                try
                {
                    LOG(LogLevel::INFO, "SilkCasket::Build::Builder", "Build", "build", "正在加密文件：" + entry.path().string());

                    // 使用按值捕获entry和key
                    futures.emplace_back(async(launch::async, [entry, key]
                                               {
                        auto encryptionData = SilkCasket::encryptFile(key, SilkCasket::Utils::File::readFile(entry.path().string()));
                        if (!encryptionData.empty()) {
                            SilkCasket::Utils::File::Vuint8ToFile(entry.path().string(), encryptionData);
                        } }));
                }
                catch (const exception &e)
                {
                    LOG(LogLevel::ERROR, "SilkCasket::Build::Builder", "Build", "build", "加密文件失败: " + entry.path().string() + " - " + e.what());
                }
            }
        }

        // 等待所有的异步操作完成
        for (auto &future : futures)
        {
            try
            {
                future.get();
            }
            catch (const exception &e)
            {
                LOG(LogLevel::ERROR, "SilkCasket::Build::Builder", "Build", "build", "异步操作失败: " + (string)e.what());
            }
        }
    }

    configureEntries(temp, Encryption);

    auto FileEntry = SilkCasket::Compress::smartCompress(SilkCasket::FileStructure::serializeEntrys(Entry), Mode);
    auto FileEntryData = SilkCasket::Compress::smartCompress(SilkCasket::FileStructure::serializeEntryData(EntryData), Mode);

    Header = {
            "SilkCasket",
            20241130,
            {(long)tempData.size() + 46, (long)FileEntry.size()},
            {(long)tempData.size() + (long)FileEntry.size() + 46, (long)FileEntryData.size()},
    };

    auto FileHeader = SilkCasket::FileStructure::serializeHeader(Header);

    Data.data.insert(Data.data.end(), FileHeader.begin(), FileHeader.end());
    Data.data.insert(Data.data.end(), tempData.begin(), tempData.end());

    Data.data.insert(Data.data.end(), FileEntry.begin(), FileEntry.end());
    Data.data.insert(Data.data.end(), FileEntryData.begin(), FileEntryData.end());


    SilkCasket::Utils::File::Vuint8ToFile(OutPath, Data.data);
    LOG(LogLevel::INFO, "SilkCasket::Build::Builder", "Build", "build", "打包完成：" + OutPath.string());
    filesystem::remove_all(temp);
}

