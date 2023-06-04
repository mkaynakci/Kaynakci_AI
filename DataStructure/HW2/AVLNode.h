#include <string>

class AVLNode {
private:
    std::string chrom;
    int pos;
    std::string altBase;
    AVLNode* left;
    AVLNode* right;

public:
    int height;
    AVLNode(std::string chrom, int pos, std::string altBase);
    AVLNode* search(std::string chrom, int pos, std::string altBase);
    AVLNode* remove(const std::string& chrom, int pos, const std::string& altBase);
    AVLNode* minValueNode(); 
    int getBalance();
    AVLNode* leftRotate();
    int max(int a, int b); 
    AVLNode* rightRotate(); 

    std::string getChrom();
    int getPos();
    std::string getAltBase();
    AVLNode* getLeft();
    AVLNode* getRight();
    int getHeight();

    void setChrom(std::string chrom);
    void setPos(int pos);
    void setAltBase(std::string altBase);
    void setLeft(AVLNode* left);
    void setRight(AVLNode* right);
    void setHeight(int height);
};

