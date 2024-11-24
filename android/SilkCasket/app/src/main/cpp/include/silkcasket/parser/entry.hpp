/*******************************************************************************
 * 文件名称: entry
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

#pragma once

#include <iostream>
#include <filesystem>
#include <utility>
#include "../structure/entry.hpp"
#include "../structure/address.hpp"
#include "../structure/verification.hpp"
#include "../utils/file.hpp"

namespace SilkCasket::Parser {

    using namespace std;

    class Entry {
    private:
        filesystem::path FilePath;
        vector<SilkCasket::FileStructure::entry> Entrys;
        SilkCasket::FileStructure::entryData Data;
        vector<SilkCasket::FileStructure::verification> Verification;
    public:
        Entry(std::filesystem::path path,
              SilkCasket::FileStructure::address entryAddress,
              SilkCasket::FileStructure::address dataAaddress,
              SilkCasket::FileStructure::address verificationAaddress
              ) {
            FilePath = std::move(path);
            Entrys = SilkCasket::FileStructure::deserializeEntrys(SilkCasket::Utils::File::readFileAddress(FilePath, entryAddress.offset, entryAddress.size));
            Data = SilkCasket::FileStructure::deserializeEntryData(SilkCasket::Utils::File::readFileAddress(FilePath, dataAaddress.offset, dataAaddress.size));
            //Verification = SilkCasket::FileStructure::deserializeVerifications(SilkCasket::Utils::File::readFileAddress(FilePath, verificationAaddress.offset, verificationAaddress.size));
        }

        SilkCasket::FileStructure::entry GetEntry(string name);
        vector<uint8_t> GetEntryData(string name);
        vector<uint8_t> GetVerification(string name, int Hash);
        bool GetEncryption(string name);
        bool GetIsFile(string name);
    };

}