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



void SilkCasket::Build::Builder::Build::build(filesystem::path Path,
                                              filesystem::path OutPath,
                                              SilkCasket::Compress::Mode::MODE Mode,
                                              array<bool, 2> Encryption,
                                              string key
                                              ) {

    auto temp = Path.parent_path() / "temp";

    SilkCasket::Utils::File::copyDirectory(Path, temp, 8096 * 1024);

    for (const auto& entry : filesystem::recursive_directory_iterator(temp)) {
        if (entry.is_regular_file()) {
            auto compressedData = SilkCasket::Compress::smartCompress(entry.path(), Mode);
            if (!compressedData.empty()) {
                Utils::File::Vuint8ToFile(entry.path(), compressedData);
            }
        }
    }

    if (Encryption.at(0)) {
        for (const auto &entry: filesystem::recursive_directory_iterator(temp)) {
            if (entry.is_regular_file()) {
                auto encryptionData = SilkCasket::Encryption().encrypt(Utils::File::readFile(entry.path()), key);
                if (!encryptionData.empty()) {
                    Utils::File::Vuint8ToFile(entry.path(), encryptionData);
                }
            }
        }
    }

    configureEntries(temp);

    auto FileEntry = SilkCasket::FileStructure::serializeEntrys(Entry);
    auto FileEntryData = SilkCasket::FileStructure::serializeEntryData(EntryData);
    auto FileVerification = SilkCasket::FileStructure::serializeVerifications(Verification);

    Header = {
            "SilkCasket",
            20241122,
            {false, false, false},
            {(long)tempData.size() + 73, (long)FileEntry.size()},
            {(long)tempData.size() + (long)FileEntry.size() + 73, (long)FileEntryData.size()},
            {(long)tempData.size() + (long)FileEntryData.size() + 73, (long)FileVerification.size()}
    };

    auto FileHeader = SilkCasket::FileStructure::serializeHeader(Header);


    Data.data.insert(Data.data.end(), FileHeader.begin(), FileHeader.end());
    Data.data.insert(Data.data.end(), tempData.begin(), tempData.end());



    if (Encryption.at(1)) {
        auto newFileEntry = SilkCasket::Encryption().encrypt(FileEntry, key);
        auto newFileEntryData = SilkCasket::Encryption().encrypt(FileEntryData, key);
        auto newFileVerification = SilkCasket::Encryption().encrypt(FileVerification, key);

        Data.data.insert(Data.data.end(), newFileEntry.begin(), newFileEntry.end());
        Data.data.insert(Data.data.end(), newFileEntryData.begin(), newFileEntryData.end());
        Data.data.insert(Data.data.end(), newFileVerification.begin(), newFileVerification.end());
    } else {
        Data.data.insert(Data.data.end(), FileEntry.begin(), FileEntry.end());
        Data.data.insert(Data.data.end(), FileEntryData.begin(), FileEntryData.end());
        Data.data.insert(Data.data.end(), FileVerification.begin(), FileVerification.end());
    }
    SilkCasket::Utils::File::Vuint8ToFile(OutPath, Data.data);
}

