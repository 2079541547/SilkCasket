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

#include <structure/entry.hpp>

std::vector <uint8_t>
SilkCasket::FileStructure::serializeEntryData(const SilkCasket::FileStructure::entryData &data) {
    vector<uint8_t> buffer;

    // 写入地址数量
    size_t numAddresses = data.Address.size();
    buffer.insert(buffer.end(), reinterpret_cast<const uint8_t *>(&numAddresses), reinterpret_cast<const uint8_t *>(&numAddresses) + sizeof(numAddresses));

    // 写入每个地址
    for (const auto &addr : data.Address)
    {
        buffer.insert(buffer.end(), reinterpret_cast<const uint8_t *>(&addr.offset), reinterpret_cast<const uint8_t *>(&addr.offset) + sizeof(addr.offset));
        buffer.insert(buffer.end(), reinterpret_cast<const uint8_t *>(&addr.size), reinterpret_cast<const uint8_t *>(&addr.size) + sizeof(addr.size));
    }

    return buffer;
}


// 将entry序列化为vector<uint8_t>
std::vector<uint8_t> serializeEntry(const SilkCasket::FileStructure::entry &entry)
{
    std::vector<uint8_t> buffer;

    // 序列化name
    std::vector<uint8_t> nameBuffer = SilkCasket::FileStructure::serializeString(entry.name);
    buffer.insert(buffer.end(), nameBuffer.begin(), nameBuffer.end());

    // 序列化isFile
    buffer.push_back(entry.isFile ? 1 : 0);

    // 序列化encryption
    buffer.push_back(entry.encryption ? 1 : 0);

    // 序列化data
    buffer.insert(buffer.end(), reinterpret_cast<const uint8_t *>(&entry.data), reinterpret_cast<const uint8_t *>(&entry.data) + sizeof(entry.data));

    // 序列化verification
    buffer.insert(buffer.end(), reinterpret_cast<const uint8_t *>(&entry.verification), reinterpret_cast<const uint8_t *>(&entry.verification) + sizeof(entry.verification));

    // 序列化compressionMode
    buffer.insert(buffer.end(), reinterpret_cast<const uint8_t *>(&entry.compressionMode), reinterpret_cast<const uint8_t *>(&entry.compressionMode) + sizeof(entry.compressionMode));

    return buffer;
}

std::vector <uint8_t>
SilkCasket::FileStructure::serializeEntrys(const vector<entry> &entries) {
    vector<uint8_t> buffer;

    // 写入entry数量
    size_t numEntries = entries.size();
    buffer.insert(buffer.end(), reinterpret_cast<const uint8_t *>(&numEntries), reinterpret_cast<const uint8_t *>(&numEntries) + sizeof(numEntries));

    // 写入每个entry
    for (const auto &entry : entries)
    {
        vector<uint8_t> entryBuffer = serializeEntry(entry);
        buffer.insert(buffer.end(), entryBuffer.begin(), entryBuffer.end());
    }

    return buffer;
}

SilkCasket::FileStructure::entryData SilkCasket::FileStructure::deserializeEntryData(const vector<uint8_t> &buffer) {
    entryData data;

    // 读取地址数量
    size_t numAddresses;
    memcpy(&numAddresses, &buffer[0], sizeof(numAddresses));

    // 读取每个地址
    size_t offset = sizeof(numAddresses);
    for (size_t i = 0; i < numAddresses; ++i)
    {
        address addr{};
        memcpy(&addr.offset, &buffer[offset], sizeof(addr.offset));
        offset += sizeof(addr.offset);
        memcpy(&addr.size, &buffer[offset], sizeof(addr.size));
        offset += sizeof(addr.size);
        data.Address.push_back(addr);
    }

    return data;
}


// 从vector<uint8_t>反序列化为entry
SilkCasket::FileStructure::entry deserializeEntry(const std::vector<uint8_t> &buffer, size_t &offset)
{
    SilkCasket::FileStructure::entry entry;

    // 反序列化name
    entry.name = SilkCasket::FileStructure::deserializeString(buffer, offset);

    // 反序列化isFile
    entry.isFile = buffer[offset++] != 0;

    // 反序列化encryption
    entry.encryption = buffer[offset++] != 0;

    // 反序列化data
    memcpy(&entry.data, &buffer[offset], sizeof(entry.data));
    offset += sizeof(entry.data);

    // 反序列化verification
    memcpy(&entry.verification, &buffer[offset], sizeof(entry.verification));
    offset += sizeof(entry.verification);

    // 反序列化compressionMode
    memcpy(&entry.compressionMode, &buffer[offset], sizeof(entry.compressionMode));
    offset += sizeof(entry.compressionMode);

    return entry;
}



std::vector <SilkCasket::FileStructure::entry> SilkCasket::FileStructure::deserializeEntrys(const vector<uint8_t> &buffer) {
    vector<entry> entries;
    // 读取entry数量
    size_t numEntries;
    memcpy(&numEntries, &buffer[0], sizeof(numEntries));

    // 读取每个entry
    size_t offset = sizeof(numEntries);
    for (size_t i = 0; i < numEntries; ++i)
    {
        entry entry = deserializeEntry(buffer, offset);
        entries.push_back(entry);
    }
    return entries;
}