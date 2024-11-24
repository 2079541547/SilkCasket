/*******************************************************************************
 * 文件名称: builder
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
#include <vector>
#include "../structure/header.hpp"
#include "../structure/data.hpp"
#include "../structure/verification.hpp"
#include "../structure/entry.hpp"
#include <array>
#include "../compress/mode.hpp"

namespace SilkCasket::Build::Builder {

    using namespace std;

    class Build{
    private:
        SilkCasket::FileStructure::header Header;
        vector<SilkCasket::FileStructure::entry> Entry;
        SilkCasket::FileStructure::entryData EntryData;
        vector<SilkCasket::FileStructure::verification> Verification;
        vector<uint8_t> tempData;
        SilkCasket::FileStructure::Data Data;

        void configureEntries(filesystem::path Path, const std::string& parentRelativePath = "", array<bool, 2> Encryption = {false, false}) {
            for (const auto& entry : std::filesystem::directory_iterator(Path)) {
                // 构建完整的相对路径
                std::string relativePath = parentRelativePath.empty() ? entry.path().lexically_relative(Path).string() : (parentRelativePath + "/" + entry.path().filename().string());

                if (std::filesystem::is_directory(entry)) {
                    SilkCasket::FileStructure::entry e = {
                            relativePath,
                            std::filesystem::is_regular_file(entry),
                            Encryption.at(1),
                            0,
                            0,
                            0
                    };
                    Entry.push_back(e);
                    // 递归调用时传递当前目录的相对路径
                    configureEntries(entry.path(), relativePath, Encryption);
                } else if (std::filesystem::is_regular_file(entry)) {
                    std::ifstream file(entry.path(), std::ios::binary);
                    std::vector<uint8_t> data((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
                    file.close();

                    tempData.insert(tempData.end(), data.begin(), data.end());

                    SilkCasket::FileStructure::address addr = {
                            (long)(tempData.size() - data.size()) + 73, // 计算正确的偏移量
                            (long)data.size()
                    };

                    EntryData.Address.push_back(addr);

                    SilkCasket::FileStructure::entry e = {
                            relativePath,
                            true,
                            Encryption.at(0),
                            (int) EntryData.Address.size() - 1,
                            0,
                            0
                    };
                    Entry.push_back(e);
                }
            }
        }

    public:
        void build(filesystem::path Path,
                   filesystem::path OutPath,
                   SilkCasket::Compress::Mode::MODE Mode = SilkCasket::Compress::Mode::MODE(),
                   array<bool, 2> Encryption = {false, false},
                   string key = "");
    };

}
