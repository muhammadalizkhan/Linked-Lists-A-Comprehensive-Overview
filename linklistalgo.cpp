#include <iostream>
#include <unordered_set>

// Node definition for singly linked list
template <typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& value) : data(value), next(nullptr) {}
};

// Singly Linked List class
template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    // ... Previous code for insertion, deletion, search, and display ...

    // Find the middle element of the linked list
    Node<T>* findMiddle() const {
        if (!head) {
            return nullptr;
        }

        Node<T>* slow = head;
        Node<T>* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Remove duplicates from an unsorted linked list using a hash set
    void removeDuplicates() {
        std::unordered_set<T> uniqueSet;
        Node<T>* current = head;
        Node<T>* prev = nullptr;

        while (current) {
            if (uniqueSet.count(current->data)) {
                prev->next = current->next;
                delete current;
                current = prev->next;
            } else {
                uniqueSet.insert(current->data);
                prev = current;
                current = current->next;
            }
        }
    }

    // Recursive reversal of the linked list
    void recursiveReverse(Node<T>* current, Node<T>* prev = nullptr) {
        if (!current) {
            head = prev;
            return;
        }

        Node<T>* next = current->next;
        current->next = prev;
        recursiveReverse(next, current);
    }

    // Destructor to free memory
    ~LinkedList() {
        // ... Previous code for deleting nodes ...
    }
};

int main() {
    // Example of finding the middle element
    LinkedList<int> middleList;
    for (int i = 1; i <= 5; ++i) {
        middleList.insertAtEnd(i);
    }
    Node<int>* middleNode = middleList.findMiddle();
    std::cout << "Middle Element: " << (middleNode ? middleNode->data : -1) << std::endl; // Output: 3

    // Example of removing duplicates
    LinkedList<int> duplicatesList;
    for (int i = 1; i <= 5; ++i) {
        duplicatesList.insertAtEnd(i);
        duplicatesList.insertAtEnd(i); // Introducing duplicates
    }
    duplicatesList.display(); // Output: 1 -> 1 -> 2 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5 -> 5 -> nullptr
    duplicatesList.removeDuplicates();
    duplicatesList.display(); // Output: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr

    // Example of recursive reversal
    LinkedList<int> recursiveReverseList;
    for (int i = 1; i <= 5; ++i) {
        recursiveReverseList.insertAtEnd(i);
    }
    recursiveReverseList.display(); // Output: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    recursiveReverseList.recursiveReverse(recursiveReverseList.getHead());
    recursiveReverseList.display(); // Output: 5 -> 4 -> 3 -> 2 -> 1 -> nullptr

    return 0;
}
