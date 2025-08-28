#include "UnsortedLinkedListDict.hpp"

void UnsortedLinkedListDict::insert(int key) {
    // Creates a new node. It will set head to keyNode's next, and then head equal to keyNode.
    // This pushes back the list each time a new node is added, making the new node the head.

    Node* keyNode = new Node;
    keyNode->data = key;
    keyNode->next = nullptr;

    if (head == nullptr) {
        head = keyNode;
        return;
    }

    keyNode->next = head;
    head = keyNode;
}

bool UnsortedLinkedListDict::lookup(int key) const {

    // Scans through the linked list from the head, returning true if the data key is found

    if (head == nullptr) {
        return false;
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
void UnsortedLinkedListDict::remove(int key) {

    // Scans through the linked list, if the key is found, it sets the prev node to the current nodes next, and then deletes the key node.

    if (head == nullptr) {
        return;
    }

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head->next;
    Node* prev = head;

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