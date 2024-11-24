/*******************************************************************************
 * 文件名称: compress
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


#include <iostream>
#include <compress/compress.hpp>
#include <utils/file.hpp>
#include <log.hpp>
#include <compress/lzw.hpp>


std::vector<uint8_t> compressData(const std::vector<uint8_t>& data, SilkCasket::Compress::Mode::Mode mode) {
    using namespace SilkCasket::Compress::Mode;

    switch (mode) {
        case Storage:
        {
            std::vector<uint8_t> result;
            int modeValue = static_cast<int>(mode);
            result.insert(result.end(), reinterpret_cast<const uint8_t*>(&modeValue), reinterpret_cast<const uint8_t*>(&modeValue) + sizeof(int));
            result.insert(result.end(), data.begin(), data.end());
            return result;
        }
        case Default:
            // 实现 Default 压缩
            throw std::runtime_error("Default 压缩未实现");
        case LZ4:
            // 实现 LZ4 压缩
            throw std::runtime_error("LZ4 压缩未实现");
        case LZW: {
            std::vector<uint8_t> result;
            auto _a = SilkCasket::Compress::LZW::compress(data);
            int modeValue = static_cast<int>(mode);
            result.insert(result.end(), reinterpret_cast<const uint8_t*>(&modeValue), reinterpret_cast<const uint8_t*>(&modeValue) + sizeof(int));
            result.insert(result.end(), _a.begin(), _a.end());
            return result;
        }
        case LZAM:
            // 实现 LZAM 压缩
            throw std::runtime_error("LZAM 压缩未实现");
        default:
            throw std::invalid_argument("未知的压缩模式");
    }
}




std::vector <uint8_t>
SilkCasket::Compress::smartCompress(filesystem::path inputFile, SilkCasket::Compress::Mode::MODE compress) {
    namespace fs = std::filesystem;

    if (!fs::exists(inputFile)) {
        LOG(LogLevel::ERROR, "SilkCasket::Compress", "smartCompress", "文件不存在！");
        return {};
    }

    auto data = Utils::File::readFile(inputFile);

    std::vector<std::pair<Mode::Mode, fs::path>> compressedFiles;

    if (compress.Storage) {
        auto compressedData = compressData(data, Mode::Storage);
        fs::path tempFile = fs::temp_directory_path() / ("compressed_" + std::to_string(Mode::Storage) + ".tmp");
        Utils::File::Vuint8ToFile(tempFile, compressedData);
        compressedFiles.emplace_back(Mode::Storage, tempFile);
    }
    if (compress.Default) {
        auto compressedData = compressData(data, Mode::Default);
        fs::path tempFile = fs::temp_directory_path() / ("compressed_" + std::to_string(Mode::Default) + ".tmp");
        Utils::File::Vuint8ToFile(tempFile, compressedData);
        compressedFiles.emplace_back(Mode::Default, tempFile);
    }
    if (compress.LZ4) {
        auto compressedData = compressData(data, Mode::LZ4);
        fs::path tempFile = fs::temp_directory_path() / ("compressed_" + std::to_string(Mode::LZ4) + ".tmp");
        Utils::File::Vuint8ToFile(tempFile, compressedData);
        compressedFiles.emplace_back(Mode::LZ4, tempFile);
    }
    if (compress.LZW) {
        auto compressedData = compressData(data, Mode::LZW);
        fs::path tempFile = fs::temp_directory_path() / ("compressed_" + std::to_string(Mode::LZW) + ".tmp");
        Utils::File::Vuint8ToFile(tempFile, compressedData);
        compressedFiles.emplace_back(Mode::LZW, tempFile);
    }
    if (compress.LZAM) {
        auto compressedData = compressData(data, Mode::LZAM);
        fs::path tempFile = fs::temp_directory_path() / ("compressed_" + std::to_string(Mode::LZAM) + ".tmp");
        Utils::File::Vuint8ToFile(tempFile, compressedData);
        compressedFiles.emplace_back(Mode::LZAM, tempFile);
    }

    if (compressedFiles.empty()) {
        LOG(LogLevel::ERROR, "SilkCasket::Compress", "smartCompress", "没有启用任何压缩模式！");
        return {};
    }

    // 找到最小的压缩结果
    auto smallestResult = *std::min_element(compressedFiles.begin(), compressedFiles.end(),
                                            [](const auto& a, const auto& b) {
                                                return fs::file_size(a.second) < fs::file_size(b.second);
                                            });

    // 读取最小的压缩结果
    std::vector<uint8_t> result = Utils::File::readFile(smallestResult.second);

    // 删除所有临时文件
    for (const auto& [mode, path] : compressedFiles) {
        fs::remove(path);
    }

    return result;
}