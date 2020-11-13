// Original Source: https://rosettacode.org/wiki/Huffman_coding#C.2B.2B

#include <iostream>
#include <queue>
#include <map>
#include <climits> // for CHAR_BIT
#include <iterator>
#include <algorithm>
#include <cstring>
 
const int UniqueSymbols = 1 << CHAR_BIT;
const char* SampleString = "this is an example for huffman encoding";
 
typedef std::vector<bool> HuffCode;
typedef std::map<char, HuffCode> HuffCodeMap;
 
class INode {
public:
    const int f;
 
    virtual ~INode() {}
 
protected:
    INode(int f) : f(f) {}
};
 
class InternalNode : public INode {
public:
    INode *const left;
    INode *const right;
 
    InternalNode(INode* c0, INode* c1) : INode(c0->f + c1->f), left(c0), right(c1) {}
    ~InternalNode()
    {
        delete left;
        delete right;
    }
};
 
class LeafNode : public INode
{
public:
    const char c;
 
    LeafNode(int f, char c) : INode(f), c(c) {}
};
 
struct NodeCmp
{
    bool operator()(const INode* lhs, const INode* rhs) const { return lhs->f > rhs->f; }
};
 
INode* BuildTree(const int (&frequencies)[UniqueSymbols])
{
    std::priority_queue<INode*, std::vector<INode*>, NodeCmp> trees;
 
    for (int i = 0; i < UniqueSymbols; ++i)
    {
        if(frequencies[i] != 0)
            trees.push(new LeafNode(frequencies[i], (char)i));
    }
    while (trees.size() > 1)
    {
        INode* childR = trees.top();
        trees.pop();
 
        INode* childL = trees.top();
        trees.pop();
 
        INode* parent = new InternalNode(childR, childL);
        trees.push(parent);
    }
    return trees.top();
}
 
void GenerateCodes(const INode* node, const HuffCode& prefix, HuffCodeMap& outCodes)
{
    if (const LeafNode* lf = dynamic_cast<const LeafNode*>(node))
    {
        outCodes[lf->c] = prefix;
    }
    else if (const InternalNode* in = dynamic_cast<const InternalNode*>(node))
    {
        HuffCode leftPrefix = prefix;
        leftPrefix.push_back(false);
        GenerateCodes(in->left, leftPrefix, outCodes);
 
        HuffCode rightPrefix = prefix;
        rightPrefix.push_back(true);
        GenerateCodes(in->right, rightPrefix, outCodes);
    }
}

void huffmanCompression(void **huffmanTree, std::vector<uint8_t> **toCompress, int numVectors) {
  int frequencies[UniqueSymbols] = {0};
  int vecSize = 0;
  for (int i = 0; i < numVectors; i++) {
    vecSize = toCompress[i]->size();
    for (int j = 0; j < vecSize; j++) {
      frequencies[toCompress[i]->at(j)]++;
    }
  }

  INode* root = BuildTree(frequencies);
  *huffmanTree = root;
 
  HuffCodeMap codes;
  GenerateCodes(root, HuffCode(), codes);

  std::vector<uint8_t> compressed;

  uint8_t currByte = 0;
  uint8_t currBit = 0;
  for (int i = 0; i < numVectors; i++) {
    vecSize = toCompress[i]->size();
    for (int j = 0; j < vecSize; j++) {
      auto &byteEncoding = codes[toCompress[i]->at(j)];
      for (int k = 0; k < byteEncoding.size(); k++) {
        currByte |= byteEncoding[k] << (7-currBit);
        currBit++;
        if (currBit == 8) {
          currBit = 0;
          compressed.push_back(currByte);
          currByte = 0;
        }
      }
    }
  }
  // There were some trailing bits
  if (currBit > 0) compressed.push_back(currByte);

  toCompress[0]->swap(compressed);
  for (int i = 1; i < numVectors; i++) {
    // Make sure the vector is cleared out (i.e. deallocated, not just size set to 0)
    std::vector<uint8_t>().swap(*toCompress[i]);
  }
}

void huffmanDecompression(void **huffmanTree, std::vector<uint8_t> **outputVectors, int numVectors) {
  std::vector<uint8_t> compressedContents;
  compressedContents.swap(*outputVectors[0]);

  INode *root = (INode *)*huffmanTree;
  INode *next = root;
  int k = 0;
  for (int i = 0; i < compressedContents.size() && k < numVectors; i++) {
    for (int j = 7; j >= 0 && k < numVectors; j--) {
        InternalNode *in = (InternalNode*) next;
        if (compressedContents[i] & (1 << j)) {
          next = in->right;
        } else {
          next = in->left;
        }
      if (LeafNode *lf = dynamic_cast<LeafNode *>(next)) {
        outputVectors[k]->push_back(lf->c);
        if (lf->c == '\0') {
          k++;
        }
        next = root;
      }
    }
  }
  delete root;
  *huffmanTree = NULL;
}

/*
int main(int argc, char *argv[])
{
    // Build frequency table
    int frequencies[UniqueSymbols] = {0};
    frequencies[0]++;
    if (argc == 1) {
      const char* ptr = SampleString;
      while (*ptr != '\0')
        ++frequencies[*ptr++];
    } else {
      for (int i = 1; i < argc; i++) {
        int len = strlen(argv[i]);
        for (int j = 0; j < len; j++) {
          ++frequencies[argv[i][j]];
        }
      }
    }
 
    INode* root = BuildTree(frequencies);
 
    HuffCodeMap codes;
    GenerateCodes(root, HuffCode(), codes);

    std::vector<uint8_t> output;
    uint8_t currByte = 0;
    uint8_t currBit = 0;
    uint8_t encoding; 
    if (argc == 1) {
      for (int i = 0; i < strlen(SampleString)+1; i++) {
        for (int j = 0; j < codes[SampleString[i]].size(); j++) {
          currByte |= (codes[SampleString[i]][j] ? 1 : 0) << (7-currBit);
          currBit++;
          if (currBit == 8) {
            currBit = 0;
            output.push_back(currByte);
            currByte = 0;
          }
        }
      }
      output.push_back(currByte);

      for (int i = 0; i < output.size(); i++) {
        printf("%X", output[i]);
      }
      printf("\n");

      INode *next = root;
      for (int i = 0; i < output.size(); i++) {
        for (int j = 7; j >= 0; j--) {
            InternalNode *in = (InternalNode*) next;
            if (output[i] & (1 << j)) {
              next = in->right;
            } else {
              next = in->left;
            }
          if (LeafNode *lf = dynamic_cast<LeafNode *>(next)) {
            std::cout << lf->c;
            next = root;
          }
        }
      }
      std::cout << std::endl;
      if (next != root) std::cout << "Incomplete!\n" << std::endl;
    }

    delete root;

 
    for (HuffCodeMap::const_iterator it = codes.begin(); it != codes.end(); ++it)
    {
        std::cout << it->first << " (0x" << std::hex << (int)it->first << ") " << std::dec;
        std::copy(it->second.begin(), it->second.end(),
                  std::ostream_iterator<bool>(std::cout));
        std::cout << std::endl;
    }
    return 0;
}
*/
