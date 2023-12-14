include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& value) : data(value), next(nullptr) {}
};
template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}
    void insertAtBeginning(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(const T& data) {
        Node<T>* newNode = new Node<T>(data);

        if (!head) {
            head = newNode;
            return;
        }

        Node<T>* current = head;
        while (current->next) {
            current = current->next;
        }

        current->next = newNode;
    }
    void insertAtPosition(const T& data, int position) {
        if (position < 0) {
            std::cerr << "Invalid position\n";
            return;
        }

        Node<T>* newNode = new Node<T>(data);

        if (position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node<T>* current = head;
        for (int i = 0; i < position - 1 && current; ++i) {
            current = current->next;
        }

        if (!current) {
            std::cerr << "Invalid position\n";
            delete newNode;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
    void deleteNode(const T& data) {
        Node<T>* current = head;
        Node<T>* prev = nullptr;

        while (current && current->data != data) {
            prev = current;
            current = current->next;
        }

        if (!current) {
            std::cerr << "Node not found\n";
            return;
        }

        if (!prev) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
    }
    bool search(const T& data) const {
        Node<T>* current = head;

        while (current) {
            if (current->data == data) {
                return true;
            }
            current = current->next;
        }

        return false;
    }

    void display() const {
        Node<T>* current = head;

        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
        }

        std::cout << "nullptr\n";
    }

    ~LinkedList() {
        Node<T>* current = head;
        Node<T>* next = nullptr;

        while (current) {
            next = current->next;
            delete current;
            current = next;
        }

        head = nullptr;
    }
};

int main() {
    LinkedList<int> myList;
    myList.insertAtEnd(1);
    myList.insertAtEnd(2);
    myList.insertAtBeginning(0);
    myList.insertAtPosition(3, 3);
    myList.display(); // Output: 0 -> 1 -> 2 -> 3 -> nullptr

    myList.deleteNode(2);
    myList.display(); // Output: 0 -> 1 -> 3 -> nullptr

    std::cout << "Search for 1: " << (myList.search(1) ? "Found" : "Not found") << std::endl; // Output: Found

    struct DoublyNode {
        int data;
        DoublyNode* next;
        DoublyNode* prev;

        DoublyNode(int value) : data(value), next(nullptr), prev(nullptr) {}
    };

    DoublyNode* head = new DoublyNode(1);
    DoublyNode* second = new DoublyNode(2);
    DoublyNode* third = new DoublyNode(3);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    delete head;
    delete second;
    delete third;

    return 0;
}
