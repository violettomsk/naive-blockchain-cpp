/**
 * Block_chain.h
 */

#ifndef NAIVE_BLOCKCHAIN_BLOCK_CHAIN_H
#define NAIVE_BLOCKCHAIN_BLOCK_CHAIN_H

#include <cstdint>
#include <vector>
#include <iostream>

#include "block.h"

class BlockChain {
public:
    BlockChain();
    void AddBlock(Block _block);

private:
    uint32_t m_difficulty;
    std::vector<Block> m_chain;

    Block GetLastBlock() const;
};

#endif