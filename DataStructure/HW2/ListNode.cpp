#include "ListNode.h"

ListNode::ListNode(std::string chrom, int pos, std::string altBase) {
    this->chrom = chrom;
    this->pos = pos;
    this->altBase = altBase;
    this->next = nullptr;
}

std::string ListNode::getChrom() {
    return this->chrom;
}

int ListNode::getPos() {
    return this->pos;
}

std::string ListNode::getAltBase() {
    return this->altBase;
}

ListNode* ListNode::getNext() {
    return this->next;
}

void ListNode::setChrom(std::string chrom) {
    this->chrom = chrom;
}

void ListNode::setPos(int pos) {
    this->pos = pos;
}

void ListNode::setAltBase(std::string altBase) {
    this->altBase = altBase;
}

void ListNode::setNext(ListNode* next) {
    this->next = next;
}
