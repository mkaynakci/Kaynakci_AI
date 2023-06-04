#include <string>

class ListNode {
private:
    std::string chrom;
    int pos;
    std::string altBase;
    ListNode* next;

public:
    ListNode(std::string chrom, int pos, std::string altBase);
    std::string getChrom();
    int getPos();
    std::string getAltBase();
    ListNode* getNext();
    void setChrom(std::string chrom);
    void setPos(int pos);
    void setAltBase(std::string altBase);
    void setNext(ListNode* next);
};
