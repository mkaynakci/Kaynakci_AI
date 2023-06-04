#include "AVLTree.h"
#include <iostream>

AVLTree::AVLTree() {
    root = nullptr;
}

int AVLTree::height(AVLNode* N) {
    if (N == nullptr)
        return 0;
    return N->getHeight();
}

int AVLTree::max(int a, int b) {
    return (a > b)? a : b;
}

AVLNode* AVLTree::rightRotate(AVLNode* y) {
    AVLNode* x = y->getLeft();
    AVLNode* T2 = x->getRight();

    x->setRight(y);
    y->setLeft(T2);

    y->setHeight(max(height(y->getLeft()), height(y->getRight())) + 1);
    x->setHeight(max(height(x->getLeft()), height(x->getRight())) + 1);

    return x;
}

AVLNode* AVLTree::leftRotate(AVLNode* x) {
    AVLNode* y = x->getRight();
    AVLNode* T2 = y->getLeft();

    y->setLeft(x);
    x->setRight(T2);

    x->setHeight(max(height(x->getLeft()), height(x->getRight())) + 1);
    y->setHeight(max(height(y->getLeft()), height(y->getRight())) + 1);

    return y;
}

int AVLTree::getBalance(AVLNode* N) {
    if (N == nullptr)
        return 0;
    return height(N->getLeft()) - height(N->getRight());
}

AVLNode* AVLTree::insert(AVLNode* node, std::string chrom, int pos, std::string altBase) {
    if (node == nullptr)
        return(new AVLNode(chrom, pos, altBase));

    if (chrom < node->getChrom() || (chrom == node->getChrom() && pos < node->getPos()))
        node->setLeft(insert(node->getLeft(), chrom, pos, altBase));
    else if (chrom > node->getChrom() || (chrom == node->getChrom() && pos > node->getPos()))
        node->setRight(insert(node->getRight(), chrom, pos, altBase));
    else
        return node;

    node->setHeight(1 + max(height(node->getLeft()), height(node->getRight())));

    int balance = getBalance(node);

    if (balance > 1 && (chrom < node->getLeft()->getChrom() || (chrom == node->getLeft()->getChrom() && pos < node->getLeft()->getPos())))
        return rightRotate(node);

    if (balance < -1 && (chrom > node->getRight()->getChrom() || (chrom == node->getRight()->getChrom() && pos > node->getRight()->getPos())))
        return leftRotate(node);

    if (balance > 1 && (chrom > node->getLeft()->getChrom() || (chrom == node->getLeft()->getChrom() && pos > node->getLeft()->getPos()))) {
        node->setLeft(leftRotate(node->getLeft()));
        return rightRotate(node);
    }

    if (balance < -1 && (chrom < node->getRight()->getChrom() || (chrom == node->getRight()->getChrom() && pos < node->getRight()->getPos()))) {
        node->setRight(rightRotate(node->getRight()));
        return leftRotate(node);
    }

    return node;
}

void AVLTree::insert(std::string chrom, int pos, std::string altBase) {
    root = insert(root, chrom, pos, altBase);
}

void AVLTree::printInOrder(AVLNode* node) {
    if (node != nullptr) {
        printInOrder(node->getLeft());
        std::cout << node->getChrom() << " " << node->getPos() << " " << node->getAltBase() << std::endl;
        printInOrder(node->getRight());
    }
}

void AVLTree::printInOrder() {
    printInOrder(root);
}

void AVLTree::storeInOrder(AVLNode* node, std::vector<AVLNode*>& nodes) {
    if (node != nullptr) {
        storeInOrder(node->getLeft(), nodes);
        nodes.push_back(node);
        storeInOrder(node->getRight(), nodes);
    }
}

void AVLTree::storeInOrder(std::vector<AVLNode*>& nodes) {
    storeInOrder(root, nodes);
}


// Search method
AVLNode* AVLTree::search(const std::string& chrom, int pos, const std::string& altBase) {
    return root->search(chrom, pos, altBase);
}

// Remove method
AVLNode* AVLTree::remove(const std::string& chrom, int pos, const std::string& altBase) {
    return root->remove(chrom, pos, altBase);
}
