// BSTree.h

#include "BSTNode.h"
#include <vector>

class BSTree {
private:
    BSTNode* root;

    BSTNode* insert(BSTNode* node, std::string chrom, int pos, std::string altBase);
    BSTNode* remove(BSTNode* node, std::string chrom, int pos, std::string altBase);
    BSTNode* minValueNode(BSTNode* node);
    void storeInOrder(BSTNode* node, std::vector<BSTNode*>& nodes);

    void printInOrder(BSTNode* node);

public:
    BSTree();
    BSTNode* search(std::string chrom, int pos, std::string altBase);
    void insert(std::string chrom, int pos, std::string altBase);
    void remove(std::string chrom, int pos, std::string altBase);
    void printInOrder();

    void storeInOrder(std::vector<BSTNode*>& nodes);

};

