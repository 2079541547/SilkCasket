/*******************************************************************************
 * 文件名称: lz4
 * 项目名称: SilkCasket
 * 创建时间: 2024/11/29
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

#include <compress/lz4.hpp>
#include <lz4.h>

std::vector<uint8_t> SilkCasket::Compress::LZ4::compress(const vector<uint8_t> &data) {

    const size_t inputSize = data.size();
    const size_t maxCompressedSize = LZ4_compressBound(inputSize); // 获取最大压缩后的大小
    std::vector<uint8_t> compressed(maxCompressedSize); // 创建压缩后的存储空间
    const size_t compressedSize = LZ4_compress_default(reinterpret_cast<const char*>(data.data()), // 输入数据
                                                       reinterpret_cast<char*>(compressed.data()), // 输出缓冲区
                                                       inputSize, // 输入大小
                                                       maxCompressedSize); // 最大压缩大小

    // 如果压缩成功，调整压缩向量的大小
    if (compressedSize > 0) {
        compressed.resize(compressedSize);
    } else {
        // 压缩失败处理
        throw std::runtime_error("Compression failed.");
    }
    return compressed;
}


std::vector <uint8_t> SilkCasket::Compress::LZ4::decompress(const vector<uint8_t> &compressed) {

    const size_t inputSize = compressed.size();
    // 假设解压缩后的数据大小不会超过原始数据大小
    // 在实际应用中，可以根据实际情况调整这个值
    std::vector<uint8_t> decompressed(compressed.size() * 5); // 创建解压缩后的存储空间

    const size_t decompressedSize = LZ4_decompress_safe(reinterpret_cast<const char*>(compressed.data()), // 输入数据
                                                        reinterpret_cast<char*>(decompressed.data()), // 输出缓冲区
                                                        inputSize, // 输入大小
                                                        decompressed.size()); // 解压缩后的最大大小

    // 如果解压缩成功，调整解压缩向量的大小
    if (decompressedSize > 0) {
        decompressed.resize(decompressedSize);
    } else {
        // 解压缩失败处理
        throw std::runtime_error("Decompression failed.");
    }


    return decompressed;
}
