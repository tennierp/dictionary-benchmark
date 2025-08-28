#pragma once
#include "Dictionary.hpp"

class UnsortedLinkedListDict : public Dictionary {
public:
    void insert(int) override;
    bool lookup(int) const override;
    void remove(int) override;

private:

    // Node structure used to build the linked list with data keys and next pointers
    struct Node{
        int data;
        Node* next;
    };
    Node* head = nullptr;
};
