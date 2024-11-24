/*******************************************************************************
 * 文件名称: verification
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

#include <structure/verification.hpp>

std::vector <uint8_t> SilkCasket::FileStructure::serializeVerification(
        const SilkCasket::FileStructure::verification &ver) {
    vector<uint8_t> buffer;

    // 序列化每个address成员
    buffer.insert(buffer.end(), reinterpret_cast<const uint8_t*>(&ver.SilkHash32.offset), reinterpret_cast<const uint8_t*>(&ver.SilkHash32.offset) + sizeof(ver.SilkHash32.offset));
    buffer.insert(buffer.end(), reinterpret_cast<const uint8_t*>(&ver.SilkHash32.size), reinterpret_cast<const uint8_t*>(&ver.SilkHash32.size) + sizeof(ver.SilkHash32.size));

    buffer.insert(buffer.end(), reinterpret_cast<const uint8_t*>(&ver.SilkHash64.offset), reinterpret_cast<const uint8_t*>(&ver.SilkHash64.offset) + sizeof(ver.SilkHash64.offset));
    buffer.insert(buffer.end(), reinterpret_cast<const uint8_t*>(&ver.SilkHash64.size), reinterpret_cast<const uint8_t*>(&ver.SilkHash64.size) + sizeof(ver.SilkHash64.size));

    buffer.insert(buffer.end(), reinterpret_cast<const uint8_t*>(&ver.SilkHash128.offset), reinterpret_cast<const uint8_t*>(&ver.SilkHash128.offset) + sizeof(ver.SilkHash128.offset));
    buffer.insert(buffer.end(), reinterpret_cast<const uint8_t*>(&ver.SilkHash128.size), reinterpret_cast<const uint8_t*>(&ver.SilkHash128.size) + sizeof(ver.SilkHash128.size));

    buffer.insert(buffer.end(), reinterpret_cast<const uint8_t*>(&ver.SilkHash256.offset), reinterpret_cast<const uint8_t*>(&ver.SilkHash256.offset) + sizeof(ver.SilkHash256.offset));
    buffer.insert(buffer.end(), reinterpret_cast<const uint8_t*>(&ver.SilkHash256.size), reinterpret_cast<const uint8_t*>(&ver.SilkHash256.size) + sizeof(ver.SilkHash256.size));

    buffer.insert(buffer.end(), reinterpret_cast<const uint8_t*>(&ver.SilkHash512.offset), reinterpret_cast<const uint8_t*>(&ver.SilkHash512.offset) + sizeof(ver.SilkHash512.offset));
    buffer.insert(buffer.end(), reinterpret_cast<const uint8_t*>(&ver.SilkHash512.size), reinterpret_cast<const uint8_t*>(&ver.SilkHash512.size) + sizeof(ver.SilkHash512.size));

    buffer.insert(buffer.end(), reinterpret_cast<const uint8_t*>(&ver.SilkHash1024.offset), reinterpret_cast<const uint8_t*>(&ver.SilkHash1024.offset) + sizeof(ver.SilkHash1024.offset));
    buffer.insert(buffer.end(), reinterpret_cast<const uint8_t*>(&ver.SilkHash1024.size), reinterpret_cast<const uint8_t*>(&ver.SilkHash1024.size) + sizeof(ver.SilkHash1024.size));

    return buffer;
}

std::vector <uint8_t> SilkCasket::FileStructure::serializeVerifications(
        const vector<SilkCasket::FileStructure::verification> &verifications) {
    vector<uint8_t> buffer;

    // 写入verification数量
    size_t numVerifications = verifications.size();
    buffer.insert(buffer.end(), reinterpret_cast<const uint8_t*>(&numVerifications), reinterpret_cast<const uint8_t*>(&numVerifications) + sizeof(numVerifications));

    // 写入每个verification
    for (const auto& ver : verifications) {
        vector<uint8_t> verBuffer = serializeVerification(ver);
        buffer.insert(buffer.end(), verBuffer.begin(), verBuffer.end());
    }

    return buffer;
}


SilkCasket::FileStructure::verification
SilkCasket::FileStructure::deserializeVerification(const vector<uint8_t> &buffer, size_t &offset) {
    verification ver;
    // 反序列化每个address成员
    memcpy(&ver.SilkHash32.offset, &buffer[offset], sizeof(ver.SilkHash32.offset));
    offset += sizeof(ver.SilkHash32.offset);
    memcpy(&ver.SilkHash32.size, &buffer[offset], sizeof(ver.SilkHash32.size));
    offset += sizeof(ver.SilkHash32.size);

    memcpy(&ver.SilkHash64.offset, &buffer[offset], sizeof(ver.SilkHash64.offset));
    offset += sizeof(ver.SilkHash64.offset);
    memcpy(&ver.SilkHash64.size, &buffer[offset], sizeof(ver.SilkHash64.size));
    offset += sizeof(ver.SilkHash64.size);

    memcpy(&ver.SilkHash128.offset, &buffer[offset], sizeof(ver.SilkHash128.offset));
    offset += sizeof(ver.SilkHash128.offset);
    memcpy(&ver.SilkHash128.size, &buffer[offset], sizeof(ver.SilkHash128.size));
    offset += sizeof(ver.SilkHash128.size);

    memcpy(&ver.SilkHash256.offset, &buffer[offset], sizeof(ver.SilkHash256.offset));
    offset += sizeof(ver.SilkHash256.offset);
    memcpy(&ver.SilkHash256.size, &buffer[offset], sizeof(ver.SilkHash256.size));
    offset += sizeof(ver.SilkHash256.size);

    memcpy(&ver.SilkHash512.offset, &buffer[offset], sizeof(ver.SilkHash512.offset));
    offset += sizeof(ver.SilkHash512.offset);
    memcpy(&ver.SilkHash512.size, &buffer[offset], sizeof(ver.SilkHash512.size));
    offset += sizeof(ver.SilkHash512.size);

    memcpy(&ver.SilkHash1024.offset, &buffer[offset], sizeof(ver.SilkHash1024.offset));
    offset += sizeof(ver.SilkHash1024.offset);
    memcpy(&ver.SilkHash1024.size, &buffer[offset], sizeof(ver.SilkHash1024.size));
    offset += sizeof(ver.SilkHash1024.size);

    return ver;
}

std::vector <SilkCasket::FileStructure::verification>
SilkCasket::FileStructure::deserializeVerifications(const vector<uint8_t> &buffer) {
    vector<verification> verifications;

    // 读取verification数量
    size_t numVerifications;
    memcpy(&numVerifications, &buffer[0], sizeof(numVerifications));

    // 读取每个verification
    size_t offset = sizeof(numVerifications);
    for (size_t i = 0; i < numVerifications; ++i) {
        verification ver = deserializeVerification(buffer, offset);
        verifications.push_back(ver);
    }

    return verifications;
}