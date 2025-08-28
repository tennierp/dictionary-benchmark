#include "SortedLinkedListDict.hpp"

void SortedLinkedListDict::insert(int key) {

    // Inserts a new node by scanning for the key that is larger than the current->data
    // Once it finds it, it places the node in between the previous and currently found node.

    Node* keyNode = new Node;
    keyNode->data = key;
    keyNode->next = nullptr;

    if (head == nullptr || head->data >= key) {
        keyNode->next = head;
        head = keyNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && key > current->next->data) {
        current = current->next;
    }

    keyNode->next = current->next;
    current->next = keyNode;
}

bool SortedLinkedListDict::lookup(int key) const {

    // Scans the list from the head to the last node, returns true if the key is found

    if (head == nullptr) {
        return false;
    } else if (head->data == key) {
        return true;
    }

    Node* current = head;
    while (current != nullptr) {
        if (current->data == key) {
            return true;
        }
        current = current->next;
    }

    return false;
}

void SortedLinkedListDict::remove(int key) {

    // Creates a prev and current node.
    // Scans through the linked list for the key, if found, it will set the previous node to the key's next node and delete the key node.

    if (head == nullptr) return;

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* prev = head;
    Node* current = head->next;

    while (current != nullptr) {
        if (current->data == key) {
            prev->next = current->next;
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}