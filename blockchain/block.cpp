#include "block.h"
#include "./../crypto/sha256.h"
#include <sstream>
#include <iostream>

Block::Block(uint32_t _indexIn, const std::string &_dataIn)
:m_index(_indexIn), m_data(_dataIn)
{
    std::cout << "[Block][New Block...]\n";
    m_nonce = -1;
    m_time = time(nullptr);
}

std::string Block::GetHash() {
    return m_hash;
}

void Block::MineBlock(uint32_t _difficulty) {
    std::cout << "[Start mining...]\n";

    char cstr[_difficulty + 1];

    for (uint32_t i = 0; i < _difficulty; ++i) {
        cstr[i] = '0';
    }

    cstr[_difficulty] = '\0';

    std::string str(cstr);

    std::cout << "[MineBlock][Start PoW:....]\n";

    do {
        std::cout << "[MineBlock][Nonce value = " << m_nonce << " ]\n";
        m_nonce++;
        m_hash = CalculateHash();
        std::cout << "[MineBlock][Hash Value = " << m_hash << " ]\n";
    } while (m_hash.substr(0, _difficulty) != str);

    std::cout << "Block mined: " << m_hash << std::endl;
}

inline std::string Block::CalculateHash() const {
    std::cout << "[Calculating Hash]\n";
    std::stringstream ss;

    ss << m_index << m_time << m_data << m_nonce << PrevHash;

    return sha256(ss.str());
}