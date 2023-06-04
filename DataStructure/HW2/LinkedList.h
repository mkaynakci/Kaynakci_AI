#include "ListNode.h"
#include <string>
#include <vector>


class LinkedList {
private:
    ListNode* head;
    ListNode* tail;

public:
    LinkedList();
    ~LinkedList();
    void insert(std::string chrom, int pos, std::string altBase);
    void remove(std::string chrom, int pos, std::string altBase);
    ListNode* search(std::string chrom, int pos, std::string altBase);
    void printList();
    
    void storeNodes(std::vector<ListNode*>& nodes);
};
