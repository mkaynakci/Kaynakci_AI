#include "BSTNode.h"

BSTNode::BSTNode(std::string chrom, int pos, std::string altBase) : chrom(chrom), pos(pos), altBase(altBase), left(nullptr), right(nullptr) {}

std::string BSTNode::getChrom() {
    return chrom;
}

int BSTNode::getPos() {
    return pos;
}

std::string BSTNode::getAltBase() {
    return altBase;
}

BSTNode* BSTNode::getLeft() {
    return left;
}

BSTNode* BSTNode::getRight() {
    return right;
}

void BSTNode::setLeft(BSTNode* left) {
    this->left = left;
}

void BSTNode::setRight(BSTNode* right) {
    this->right = right;
}


void BSTNode::setChrom(std::string chrom) {
    this->chrom = chrom;
}

void BSTNode::setPos(int pos) {
    this->pos = pos;
}

void BSTNode::setAltBase(std::string altBase) {
    this->altBase = altBase;
}
