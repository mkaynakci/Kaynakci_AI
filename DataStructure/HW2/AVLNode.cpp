#include "AVLNode.h"

AVLNode::AVLNode(std::string chrom, int pos, std::string altBase) {
    this->chrom = chrom;
    this->pos = pos;
    this->altBase = altBase;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 1;
}

std::string AVLNode::getChrom() {
    return chrom;
}

int AVLNode::getPos() {
    return pos;
}

std::string AVLNode::getAltBase() {
    return altBase;
}

AVLNode* AVLNode::getLeft() {
    return left;
}

AVLNode* AVLNode::getRight() {
    return right;
}

int AVLNode::getHeight() {
    return height;
}

void AVLNode::setChrom(std::string chrom) {
    this->chrom = chrom;
}

void AVLNode::setPos(int pos) {
    this->pos = pos;
}

void AVLNode::setAltBase(std::string altBase) {
    this->altBase = altBase;
}

void AVLNode::setLeft(AVLNode* left) {
    this->left = left;
}

void AVLNode::setRight(AVLNode* right) {
    this->right = right;
}

void AVLNode::setHeight(int height) {
    this->height = height;
}


// Search method
AVLNode* AVLNode::search(const std::string& chrom, int pos, const std::string& altBase) {
    if (this == nullptr) {
        return nullptr;
    } else if (this->chrom == chrom && this->pos == pos && this->altBase == altBase) {
        return this;
    } else if (this->chrom > chrom || (this->chrom == chrom && this->pos > pos)) {
        return left->search(chrom, pos, altBase);
    } else {
        return right->search(chrom, pos, altBase);
    }
}

// Remove method
// Note: This is a complex operation that involves rebalancing the tree. 
// You might want to refer to a textbook or online resource for the full implementation.
AVLNode* AVLNode::remove(const std::string& chrom, int pos, const std::string& altBase) {
    // TODO: Implement this method
    return nullptr;
}
