// BSTNode.h

#include <string>

class BSTNode {
private:
    std::string chrom;
    int pos;
    std::string altBase;
    BSTNode* left;
    BSTNode* right;

public:
    BSTNode(std::string chrom, int pos, std::string altBase);
    std::string getChrom();
    int getPos();
    std::string getAltBase();
    BSTNode* getLeft();
    BSTNode* getRight();
    void setLeft(BSTNode* left);
    void setRight(BSTNode* right);

    void setChrom(std::string chrom);
    void setPos(int pos);
    void setAltBase(std::string altBase);

};
