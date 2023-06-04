#include "BSTree.h"
#include <iostream>
#include <vector>

BSTree::BSTree() : root(nullptr) {}

BSTNode* BSTree::insert(BSTNode* node, std::string chrom, int pos, std::string altBase) {
    if (node == nullptr) {
        return new BSTNode(chrom, pos, altBase);
    }

    if (chrom < node->getChrom() || (chrom == node->getChrom() && pos < node->getPos())) {
        node->setLeft(insert(node->getLeft(), chrom, pos, altBase));
    } else {
        node->setRight(insert(node->getRight(), chrom, pos, altBase));
    }

    return node;
}

BSTNode* BSTree::minValueNode(BSTNode* node) {
    BSTNode* current = node;

    while (current && current->getLeft() != nullptr) {
        current = current->getLeft();
    }

    return current;
}

BSTNode* BSTree::remove(BSTNode* node, std::string chrom, int pos, std::string altBase) {
    if (node == nullptr) {
        return node;
    }

    if (chrom < node->getChrom() || (chrom == node->getChrom() && pos < node->getPos())) {
        node->setLeft(remove(node->getLeft(), chrom, pos, altBase));
    } else if (chrom > node->getChrom() || (chrom == node->getChrom() && pos > node->getPos())) {
        node->setRight(remove(node->getRight(), chrom, pos, altBase));
    } else {
        if (node->getLeft() == nullptr) {
            BSTNode* temp = node->getRight();
            delete node;
            return temp;
        } else if (node->getRight() == nullptr) {
            BSTNode* temp = node->getLeft();
            delete node;
            return temp;
        }

        BSTNode* temp = minValueNode(node->getRight());
        node->setChrom(temp->getChrom());
        node->setPos(temp->getPos());
        node->setAltBase(temp->getAltBase());
        node->setRight(remove(node->getRight(), temp->getChrom(), temp->getPos(), temp->getAltBase()));
    }

    return node;
}

void BSTree::insert(std::string chrom, int pos, std::string altBase) {
    root = insert(root, chrom, pos, altBase);
}

void BSTree::remove(std::string chrom, int pos, std::string altBase) {
    root = remove(root, chrom, pos, altBase);
}

void BSTree::printInOrder(BSTNode* node) {
    if (node != nullptr) {
        printInOrder(node->getLeft());
        std::cout << node->getChrom() << " " << node->getPos() << " " << node->getAltBase() << std::endl;
        printInOrder(node->getRight());
    }
}

void BSTree::printInOrder() {
    printInOrder(root);
}


BSTNode* BSTree::search(std::string chrom, int pos, std::string altBase) {
    BSTNode* current = root;

    while (current != nullptr) {
        if (chrom == current->getChrom() && pos == current->getPos() && altBase == current->getAltBase()) {
            return current;
        } else if (chrom < current->getChrom() || (chrom == current->getChrom() && pos < current->getPos())) {
            current = current->getLeft();
        } else {
            current = current->getRight();
        }
    }

    return nullptr;
}


void BSTree::storeInOrder(std::vector<BSTNode*>& nodes) {
    storeInOrder(root, nodes);
}

void BSTree::storeInOrder(BSTNode* node, std::vector<BSTNode*>& nodes) {
    if (node != nullptr) {
        storeInOrder(node->getLeft(), nodes);
        nodes.push_back(node);
        storeInOrder(node->getRight(), nodes);
    }
}

