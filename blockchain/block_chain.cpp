#include "block_chain.h"
#include "../utils/utils.h"

BlockChain::BlockChain() {
    m_chain.emplace_back(Block(0, "Genesis Block"));
    m_difficulty = 4;
    std::cout << "[BlockChain][New chain has been initialized...][difficulty=" + string_format("%d", m_difficulty) + "]";
}

void BlockChain::AddBlock(Block _block) {
    _block.PrevHash = GetLastBlock().GetHash();
    _block.MineBlock(m_difficulty);
    m_chain.push_back(_block);
}

Block BlockChain::GetLastBlock() const {
    return m_chain.back();
}