#include <iostream>

// Node structure for singly linked list
struct NodeSingly {
    int data;
    NodeSingly* next;

    NodeSingly(int value) : data(value), next(nullptr) {}
};

// Node structure for doubly linked list
struct NodeDoubly {
    int data;
    NodeDoubly* next;
    NodeDoubly* prev;

    NodeDoubly(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Node structure for circularly linked list
struct NodeCircular {
    int data;
    NodeCircular* next;

    NodeCircular(int value) : data(value), next(nullptr) {}
};

// Singly Linked List class
class SinglyLinkedList {
private:
    NodeSingly* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // Function to add a node at the beginning
    void addToBeginning(int value) {
        NodeSingly* newNode = new NodeSingly(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to add a node at the end
    void addToEnd(int value) {
        NodeSingly* newNode = new NodeSingly(value);
        if (!head) {
            head = newNode;
            return;
        }

        NodeSingly* current = head;
        while (current->next) {
            current = current->next;
        }

        current->next = newNode;
    }

    // Function to add a node after a specified position
    void addToPosition(int position, int value) {
        NodeSingly* newNode = new NodeSingly(value);
        if (!head || position <= 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        NodeSingly* current = head;
        for (int i = 1; i < position && current->next; ++i) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Function to delete a node from a specified position
    void deleteFromPosition(int position) {
        if (!head || position <= 0) {
            return;
        }

        NodeSingly* temp = head;

        if (position == 1) {
            head = temp->next;
            delete temp;
            return;
        }

        for (int i = 1; i < position - 1 && temp->next; ++i) {
            temp = temp->next;
        }

        if (!temp->next) {
            return; // Invalid position
        }

        NodeSingly* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Function to display the linked list
    void display() {
        NodeSingly* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    NodeDoubly* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    // Function to add a node at the beginning
    void addToBeginning(int value) {
        NodeDoubly* newNode = new NodeDoubly(value);
        newNode->next = head;
        if (head) {
            head->prev = newNode;
        }
        head = newNode;
    }

    // Function to add a node at the end
    void addToEnd(int value) {
        NodeDoubly* newNode = new NodeDoubly(value);
        if (!head) {
            head = newNode;
            return;
        }

        NodeDoubly* current = head;
        while (current->next) {
            current = current->next;
        }

        current->next = newNode;
        newNode->prev = current;
    }

    // Function to add a node after a specified position
    void addToPosition(int position, int value) {
        NodeDoubly* newNode = new NodeDoubly(value);
        if (!head || position <= 0) {
            newNode->next = head;
            if (head) {
                head->prev = newNode;
            }
            head = newNode;
            return;
        }

        NodeDoubly* current = head;
        for (int i = 1; i < position && current->next; ++i) {
            current = current->next;
        }

        newNode->next = current->next;
        if (current->next) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    // Function to delete a node from a specified position
    void deleteFromPosition(int position) {
        if (!head || position <= 0) {
            return;
        }

        NodeDoubly* temp = head;

        if (position == 1) {
            head = temp->next;
            if (head) {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }

        for (int i = 1; i < position - 1 && temp->next; ++i) {
            temp = temp->next;
        }

        if (!temp->next) {
            return; // Invalid position
        }

        NodeDoubly* toDelete = temp->next;
        temp->next = temp->next->next;
        if (temp->next) {
            temp->next->prev = temp;
        }
        delete toDelete;
    }

    // Function to display the linked list
    void display() {
        NodeDoubly* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

// Circular Linked List class
class CircularLinkedList {
private:
    NodeCircular* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Function to add a node at the beginning
    void addToBeginning(int value) {
        NodeCircular* newNode = new NodeCircular(value);
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            newNode->next = head->next;
            head->next = newNode;
        }
    }

    // Function to add a node at the end
    void addToEnd(int value) {
        NodeCircular* newNode = new NodeCircular(value);
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            newNode->next = head->next;
            head->next = newNode;
            head = newNode;
        }
    }

    // Function to add a node after a specified position
    void addToPosition(int position, int value) {
        NodeCircular* newNode = new NodeCircular(value);
        if (!head || position <= 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        NodeCircular* current = head;
        for (int i = 1; i < position && current->next != head; ++i) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Function to delete a node from a specified position
    void deleteFromPosition(int position) {
        if (!head || position <= 0) {
            return;
        }

        NodeCircular* temp = head;

        if (position == 1) {
            if (temp->next == head) {
                delete temp;
                head = nullptr;
            } else {
                NodeCircular* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
            }
            return;
        }

        for (int i = 1; i < position - 1 && temp->next != head; ++i) {
            temp = temp->next;
        }

        if (temp->next == head) {
            return; // Invalid position
        }

        NodeCircular* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Function to display the linked list
    void display() {
        if (!head) {
            std::cout << "Circular Linked List is empty.\n";
            return;
        }

        NodeCircular* current = head;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);
        std::cout << std::endl;
    }
};

int main() {
    // Singly Linked List
    std::cout << "Singly Linked List:\n";
    SinglyLinkedList singlyList;
    singlyList.addToEnd(10);
    singlyList.addToEnd(20);
    singlyList.addToBeginning(5);
    singlyList.addToPosition(2, 15);
    singlyList.display();
    singlyList.deleteFromPosition(3);
    singlyList.display();
    std::cout << "\n";

    // Doubly Linked List
    std::cout << "Doubly Linked List:\n";
    DoublyLinkedList doublyList;
    doublyList.addToEnd(10);
    doublyList.addToEnd(20);
    doublyList.addToBeginning(5);
    doublyList.addToPosition(2, 15);
    doublyList.display();
    doublyList.deleteFromPosition(3);
    doublyList.display();
    std::cout << "\n";

    // Circular Linked List
    std::cout << "Circular Linked List:\n";
    CircularLinkedList circularList;
    circularList.addToEnd(10);
    circularList.addToEnd(20);
    circularList.addToBeginning(5);
    circularList.addToPosition(2, 15);
    circularList.display();
    circularList.deleteFromPosition(3);
    circularList.display();

    return 0;
}
