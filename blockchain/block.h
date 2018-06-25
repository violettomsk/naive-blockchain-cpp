
/**
 * class Block 
 */

#ifndef NAIVE_BLOCKCHAIN_BLOCK_H
#define NAIVE_BLOCKCHAIN_BLOCK_H
#include <cstdint>
#include <iostream>

class Block {
public:
    // Each block knows its previous block's hash.
    std::string PrevHash;

    // Constructor.
    Block(uint32_t _indexIn, const std::string &_dataIn);

    // public functions.
    std::string GetHash();
    void MineBlock(uint32_t _difficulty);

private:
    uint32_t m_index;
    uint64_t m_nonce;
    std::string m_data;
    std::string m_hash;
    time_t m_time;

    std::string CalculateHash() const;
};

#endif