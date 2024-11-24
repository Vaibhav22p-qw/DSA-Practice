#include <iostream>
#include <cstdlib>

using namespace std;

// Node structure
struct Node {
    int val;
    Node* next;
};

class Stack {
private:
    Node* Top; // Pointer to the top of the stack

public:
    // Constructor to initialize Top
    Stack() {
        Top = nullptr;
    }

    // Function to push an element onto the stack
    void push(int x) {
        Node* newNode = new Node; // Create a new node
        newNode->val = x;
        newNode->next = Top;
        Top = newNode; // Update Top to the new node
    }

    // Function to traverse and display the stack
    void traverse() {
        if (Top == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }

        Node* temp = Top;
        while (temp != nullptr) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free memory
    ~Stack() {
        while (Top != nullptr) {
            Node* temp = Top;
            Top = Top->next;
            delete temp; // Free the memory of the node
        }
    }
};

int main() {
    Stack stack; // Create a stack object
    int choice, value;

    while (true) {
        cout << "1. Insert" << endl;
        cout << "2. Display" << endl;
        cout << "3. Exit" << endl;
        cout << ">>> ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.traverse();
                break;
            case 3:
                exit(0);
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}

