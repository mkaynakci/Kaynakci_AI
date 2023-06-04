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


// Static method to get height of a node. Returns 0 if node is nullptr.
int AVLNode::getHeight(AVLNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
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
AVLNode* AVLNode::search(std::string chrom, int pos, std::string altBase) {
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


// Remove method implementation


// Functions for remove 

// Method to find the node with minimum value in the tree rooted at this node
AVLNode* AVLNode::minValueNode() {
    AVLNode* current = this;

    // Loop down to find the leftmost leaf
    while (current->left != nullptr) {
        current = current->left;
    }

    return current;
}

// Method to get balance factor of the node
int AVLNode::getBalance(AVLNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

/*
// Static method to get balance factor of a node. Returns 0 if node is nullptr.
static int getBalance(AVLNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return AVLNode::getHeight(node->left) - AVLNode::getHeight(node->right);
}
*/

// Method to perform a right rotation on the node
AVLNode* AVLNode::rightRotate() {
    AVLNode* x = left;
    AVLNode* T2 = x->right;

    // Perform rotation
    x->right = this;
    left = T2;

    // Update heights
    height = max(getHeight(left), getHeight(right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // Return new root
    return x;
}

// Method to perform a left rotation on the node
AVLNode* AVLNode::leftRotate() {
    AVLNode* y = right;
    AVLNode* T2 = y->left;

    // Perform rotation
    y->left = this;
    right = T2;

    // Update heights
    height = max(getHeight(left), getHeight(right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Return new root
    return y;
}

// Utility function to get maximum of two integers
int AVLNode::max(int a, int b) {
    return (a > b)? a : b;
}




AVLNode* AVLNode::remove(const std::string& chrom, int pos, const std::string& altBase) {
    // Step 1: Perform standard BST delete
    if (chrom < this->chrom || (chrom == this->chrom && pos < this->pos)) {
        if (left != nullptr) {
            left = left->remove(chrom, pos, altBase);
        }
    } else if (chrom > this->chrom || (chrom == this->chrom && pos > this->pos)) {
        if (right != nullptr) {
            right = right->remove(chrom, pos, altBase);
        }
    } else {
        // node with only one child or no child
        if ((left == nullptr) || (right == nullptr)) {
            AVLNode *temp = left ? left : right;

            // No child case
            if (temp == nullptr) {
                temp = this;
                return nullptr;
            } else { // One child case
                *this = *temp; // Copy the contents of the non-empty child
            }
            delete temp;
        } else {
            // node with two children: get the inorder
            // successor (smallest in the right subtree)
            AVLNode* temp = right->minValueNode();

            // copy the inorder successor's data to this node
            this->chrom = temp->chrom;
            this->pos = temp->pos;
            this->altBase = temp->altBase;

            // delete the inorder successor
            right = right->remove(temp->chrom, temp->pos, temp->altBase);
        }
    }

    // If the tree had only one node then return
    if (this == nullptr) {
        return nullptr;
    }

    // Step 2: Update the height of the current node
    height = 1 + max(getHeight(left), getHeight(right));

    // Step 3: Get the balance factor
    int balance = getBalance(0);

    // Step 4: If the node is unbalanced, then try out the 4 cases
    // Left Left Case
    if (balance > 1 && getBalance(left) >= 0) {
        return rightRotate();
    }

    // Left Right Case
    if (balance > 1 && getBalance(left) < 0) {
        left = left->leftRotate();
        return rightRotate();
    }

    // Right Right Case
    if (balance < -1 && getBalance(right) <= 0) {
        return leftRotate();
    }

    // Right Left Case
    if (balance < -1 && getBalance(right) > 0) {
        right = right->rightRotate();
        return leftRotate();
    }

    return this;
}
