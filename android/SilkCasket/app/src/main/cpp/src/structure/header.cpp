/*******************************************************************************
 * 文件名称: header
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

#include <structure/header.hpp>

std::vector <uint8_t>
SilkCasket::FileStructure::serializeHeader(const SilkCasket::FileStructure::header &hdr) {
    std::vector<uint8_t> buffer;

    // 写入字符串长度
    size_t idLen = hdr.identification.size();
    buffer.insert(buffer.end(), reinterpret_cast<const uint8_t*>(&idLen), reinterpret_cast<const uint8_t*>(&idLen) + sizeof(idLen));

    // 写入字符串
    buffer.insert(buffer.end(), hdr.identification.begin(), hdr.identification.end());

    // 写入其他成员
    buffer.insert(buffer.end(), reinterpret_cast<const uint8_t*>(&hdr.versionNumber), reinterpret_cast<const uint8_t*>(&hdr.versionNumber) + sizeof(hdr.versionNumber));

    // 写入 encryption 数组
    for (bool b : hdr.encryption) {
        buffer.push_back(b ? 1 : 0);
    }

    // 写入其他地址成员
    buffer.insert(buffer.end(), reinterpret_cast<const uint8_t*>(&hdr.entry), reinterpret_cast<const uint8_t*>(&hdr.entry) + sizeof(hdr.entryData));
    buffer.insert(buffer.end(), reinterpret_cast<const uint8_t*>(&hdr.entryData), reinterpret_cast<const uint8_t*>(&hdr.entryData) + sizeof(hdr.entryData));
    buffer.insert(buffer.end(), reinterpret_cast<const uint8_t*>(&hdr.verification), reinterpret_cast<const uint8_t*>(&hdr.verification) + sizeof(hdr.verification));

    return buffer;
}


SilkCasket::FileStructure::header SilkCasket::FileStructure::deserializeHeader(const std::vector<uint8_t> &buffer) {
    if (buffer.size() < sizeof(size_t) + sizeof(int) + 3 + 3 * sizeof(address)) {
        std::cerr << "缓冲区太小" << std::endl;
        throw std::runtime_error("缓冲区太小");
    }

    header hdr;

    size_t idLen;
    std::memcpy(&idLen, &buffer[0], sizeof(idLen));

    if (buffer.size() < sizeof(size_t) + idLen + sizeof(int) + 3 + 3 * sizeof(address)) {
        std::cerr << "缓冲区太小" << std::endl;
        throw std::runtime_error("缓冲区太小");
    }

    hdr.identification.resize(idLen);
    std::memcpy(&hdr.identification[0], &buffer[sizeof(size_t)], idLen);

    size_t offset = sizeof(size_t) + idLen;
    std::memcpy(&hdr.versionNumber, &buffer[offset], sizeof(hdr.versionNumber));
    offset += sizeof(hdr.versionNumber);

    // 读取 encryption 数组
    for (size_t i = 0; i < 3; ++i) {
        hdr.encryption[i] = buffer[offset] != 0;
        offset += 1;
    }

    // 读取其他地址成员
    std::memcpy(&hdr.entry, &buffer[offset], sizeof(hdr.entry));
    offset += sizeof(hdr.entry);

    std::memcpy(&hdr.entryData, &buffer[offset], sizeof(hdr.entryData));
    offset += sizeof(hdr.entryData);

    std::memcpy(&hdr.verification, &buffer[offset], sizeof(hdr.verification));
    offset += sizeof(hdr.verification);

    return hdr;
}