#include "LinkedList.h"
#include <iostream>
#include <vector>


LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

LinkedList::~LinkedList() {
    ListNode* current = this->head;
    while (current != nullptr) {
        ListNode* next = current->getNext();
        delete current;
        current = next;
    }
}

void LinkedList::insert(std::string chrom, int pos, std::string altBase) {
    ListNode* newNode = new ListNode(chrom, pos, altBase);
    if (this->head == nullptr) {
        this->head = newNode;
        this->tail = newNode;
    } else {
        this->tail->setNext(newNode);
        this->tail = newNode;
    }
}

void LinkedList::remove(std::string chrom, int pos, std::string altBase) {
    ListNode* current = this->head;
    ListNode* previous = nullptr;

    while (current != nullptr) {
        if (current->getChrom() == chrom && current->getPos() == pos && current->getAltBase() == altBase) {
            if (previous == nullptr) {
                // Node to be removed is the head node
                this->head = current->getNext();
            } else {
                // Node to be removed is not the head node
                previous->setNext(current->getNext());
            }

            if (current == this->tail) {
                // Node to be removed is the tail node
                this->tail = previous;
            }

            delete current;
            return;
        }

        previous = current;
        current = current->getNext();
    }
}

ListNode* LinkedList::search(std::string chrom, int pos, std::string altBase) {
    ListNode* current = this->head;

    while (current != nullptr) {
        if (current->getChrom() == chrom && current->getPos() == pos && current->getAltBase() == altBase) {
            return current;
        }

        current = current->getNext();
    }

    return nullptr;
}


void LinkedList::printList() {
    ListNode* current = this->head;
    while (current != nullptr) {
        std::cout << current->getChrom() << " " << current->getPos() << " " << current->getAltBase() << std::endl;
        current = current->getNext();
    }
}


void LinkedList::storeNodes(std::vector<ListNode*>& nodes) {
    ListNode* current = this->head;
    while (current != nullptr) {
        nodes.push_back(current);
        current = current->getNext();
    }
}
