#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int val;
    Node* next;
};

class Stack {
private:
    Node* Top; 
public:

    Stack() {
        Top = nullptr;
    }

    void push(int x) {
        Node* newNode = new Node; 
        newNode->val = x;
        newNode->next = Top;
        Top = newNode; 
    }

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

    ~Stack() {
        while (Top != nullptr) {
            Node* temp = Top;
            Top = Top->next;
            delete temp;
        }
    }
};

int main() {
    Stack stack; 
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

