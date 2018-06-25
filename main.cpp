#include "./blockchain/block_chain.h"
#include "./utils/utils.h"

int main() {
    BlockChain naiveBlockChain = BlockChain();
    
    for (int i = 0; i < 10; ++i) {
        std::cout << "Mining block " << i + 1 << std::endl;
        naiveBlockChain.AddBlock(Block(i + 1, string_format("Block %i data", i)));
    }

    return 0;
}