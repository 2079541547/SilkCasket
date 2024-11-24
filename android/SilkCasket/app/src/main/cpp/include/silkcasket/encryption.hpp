/*******************************************************************************
 * 文件名称: encryption
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
#include <array>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cstdint>
#include "../../lib/SilkHash/SilkHash1024.hpp"
#include <sstream>
#include <iomanip>
#include <random>

namespace SilkCasket{
    class Encryption {
    private:
        std::string KeyGeneration(const std::string &input){
            auto result = SilkHash1024::hashString(input);
            std::ostringstream oss;
            oss << std::setw(16) << std::setfill('0') << std::hex << result.part1
                << std::setw(16) << std::setfill('0') << std::hex << result.part2
                << std::setw(16) << std::setfill('0') << std::hex << result.part3
                << std::setw(16) << std::setfill('0') << std::hex << result.part4
                << std::setw(16) << std::setfill('0') << std::hex << result.part5
                << std::setw(16) << std::setfill('0') << std::hex << result.part6
                << std::setw(16) << std::setfill('0') << std::hex << result.part7
                << std::setw(16) << std::setfill('0') << std::hex << result.part8
                << std::setw(16) << std::setfill('0') << std::hex << result.part9
                << std::setw(16) << std::setfill('0') << std::hex << result.part10
                << std::setw(16) << std::setfill('0') << std::hex << result.part11
                << std::setw(16) << std::setfill('0') << std::hex << result.part12
                << std::setw(16) << std::setfill('0') << std::hex << result.part13
                << std::setw(16) << std::setfill('0') << std::hex << result.part14
                << std::setw(16) << std::setfill('0') << std::hex << result.part15
                << std::setw(16) << std::setfill('0') << std::hex << result.part16;
            return oss.str();
        }

        std::array<uint8_t, 256> generateByteMapping(const std::string &key) {
            std::array<uint8_t, 256> mapping;
            for (size_t i = 0; i < 256; ++i) {
                mapping[i] = static_cast<uint8_t>(i);
            }

            // 使用密钥生成的哈希值作为随机种子
            std::string hash = KeyGeneration(key + "\n！");
            size_t seed = std::stoul(hash.substr(0, 8), nullptr, 16);

            // 创建一个随机数生成器
            std::random_device rd;  // 用于获取随机种子
            std::mt19937 g(seed);   // 使用 Mersenne Twister 算法

            // 打乱 mapping 的元素
            std::shuffle(mapping.begin(), mapping.end(), g);

            return mapping;
        }

        std::array<uint8_t, 16> generateIV(const std::string &key){
            std::array<uint8_t, 16> iv;
            std::string hash = KeyGeneration(key + "\n去你妈的帝国主义！");
            for (size_t i = 0; i < 16; ++i)
            {
                iv[i] = static_cast<uint8_t>(hash[(i * 2) % hash.size()] - '0');
            }
            return iv;
        }

        void addRoundKey(uint8_t *state, const uint8_t *roundKey)
        {
            for (size_t i = 0; i < 16; ++i)
            {
                state[i] ^= roundKey[i];
            }
        }

        void aes128Encrypt(uint8_t *state, const uint8_t *key)
        {
            addRoundKey(state, key); // 简化的轮密钥加操作
        }

        void aes128Decrypt(uint8_t *state, const uint8_t *key)
        {
            addRoundKey(state, key); // 简化的轮密钥加操作
        }
    public:
        // 加密函数
        std::vector<uint8_t> encrypt(const std::vector<uint8_t> &plaintext, const std::string &key)
        {
            auto byteMapping = generateByteMapping(key);
            auto iv = generateIV(key);

            std::vector<uint8_t> ciphertext;
            ciphertext.insert(ciphertext.end(), iv.begin(), iv.end()); // 将IV附加到密文开头

            uint8_t lastCipherBlock[16];
            std::copy(iv.begin(), iv.end(), lastCipherBlock);

            size_t plaintextLength = plaintext.size();
            size_t paddedLength = ((plaintextLength + 15) / 16) * 16; // 计算填充后的长度

            for (size_t i = 0; i < paddedLength; i += 16)
            {
                uint8_t block[16] = {0};
                for (size_t j = 0; j < 16 && (i + j) < plaintext.size(); ++j)
                {
                    // 映射替换
                    block[j] = byteMapping[plaintext[i + j]];
                }

                // 填充最后一个块
                if (i + 16 > plaintext.size())
                {
                    uint8_t paddingValue = 16 - (plaintext.size() % 16);
                    for (size_t j = plaintext.size() % 16; j < 16; ++j)
                    {
                        block[j] = paddingValue;
                    }
                }

                // CBC模式：与前一个密文字节异或
                for (size_t j = 0; j < 16; ++j)
                {
                    block[j] ^= lastCipherBlock[j];
                }

                // AES-128加密
                aes128Encrypt(block, reinterpret_cast<const uint8_t *>(key.c_str()));

                // 更新lastCipherBlock
                std::copy(block, block + 16, lastCipherBlock);

                // 添加到密文
                ciphertext.insert(ciphertext.end(), block, block + 16);
            }

            return ciphertext;
        }

        std::vector<uint8_t> decrypt(const std::vector<uint8_t> &ciphertext, const std::string &key)
        {
            auto byteMapping = generateByteMapping(key);
            auto iv = generateIV(key);

            // 创建逆映射表
            std::array<uint8_t, 256> reverseMapping;
            for (size_t i = 0; i < 256; ++i)
            {
                reverseMapping[byteMapping[i]] = static_cast<uint8_t>(i);
            }

            // 提取IV
            std::array<uint8_t, 16> ivFromCiphertext;
            std::copy(ciphertext.begin(), ciphertext.begin() + 16, ivFromCiphertext.begin());

            std::vector<uint8_t> plaintext;
            uint8_t lastCipherBlock[16];
            std::copy(ivFromCiphertext.begin(), ivFromCiphertext.end(), lastCipherBlock);

            for (size_t i = 16; i < ciphertext.size(); i += 16)
            {
                uint8_t block[16];
                std::copy(ciphertext.begin() + i, ciphertext.begin() + i + 16, block);

                // AES-128解密
                aes128Decrypt(block, reinterpret_cast<const uint8_t *>(key.c_str()));

                // CBC模式：与前一个密文字节异或
                for (size_t j = 0; j < 16; ++j)
                {
                    block[j] ^= lastCipherBlock[j];
                }

                // 逆映射
                for (size_t j = 0; j < 16; ++j)
                {
                    plaintext.push_back(reverseMapping[block[j]]);
                }

                // 更新lastCipherBlock
                std::copy(ciphertext.begin() + i, ciphertext.begin() + i + 16, lastCipherBlock);
            }

            // 移除填充
            if (!plaintext.empty())
            {
                uint8_t paddingValue = plaintext.back();
                if (paddingValue <= 16)
                {
                    bool validPadding = true;
                    for (uint8_t j = 1; j <= paddingValue; ++j)
                    {
                        if (plaintext[plaintext.size() - j] != paddingValue)
                        {
                            validPadding = false;
                            break;
                        }
                    }
                    if (validPadding)
                    {
                        plaintext.resize(plaintext.size() - paddingValue);
                    }
                }
            }

            return plaintext;
        }
    };
}
