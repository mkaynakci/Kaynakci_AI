#ifndef AVLTREE_H
#define AVLTREE_H

#include "AVLNode.h"
#include <vector>

class AVLTree {
private:
    AVLNode* root;

    AVLNode* insert(AVLNode* node, std::string chrom, int pos, std::string altBase);
    void printInOrder(AVLNode* node);
    void storeInOrder(AVLNode* node, std::vector<AVLNode*>& nodes);
    AVLNode* minValueNode(AVLNode* node);
    int height(AVLNode* N);
    int max(int a, int b);
    AVLNode* rightRotate(AVLNode* y);
    AVLNode* leftRotate(AVLNode* x);
    int getBalance(AVLNode* N);

public:
    AVLTree();
    void insert(std::string chrom, int pos, std::string altBase);
    void printInOrder();
    void storeInOrder(std::vector<AVLNode*>& nodes);
    AVLNode* search(const std::string& chrom, int pos, const std::string& altBase);
    AVLNode* remove(const std::string& chrom, int pos, const std::string& altBase);

};

#endif
