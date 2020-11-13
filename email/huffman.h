#pragma once

#include <vector>

void huffmanCompression(void **huffmanTree, std::vector<uint8_t> **toCompress, int numVectors); 

void huffmanDecompression(void **huffmanTree, std::vector<uint8_t> **outputVectors, int numVectors); 
