
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Stack class using linked list
class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    // Constructor
    Stack() {
        top = nullptr;
    }

    // Push operation
    void push(int value) {
        Node* newNode = new Node(); // Create a new node
        newNode->data = value;      // Assign value to the node
        newNode->next = top;        // Point the new node to the current top
        top = newNode;              // Update the top pointer
        cout << value << " pushed to stack.\n";
    }

    // Display stack elements
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    return 0;
}

// Explanation:
// Node Structure: Each node contains data and a pointer next to the next node.
// Push Operation:
// A new node is created.
// The data is assigned to the new node.
// The next pointer of the new node is set to the current top.
// The top pointer is updated to the new node.
// Display Function: Traverses the stack and prints all elements.
// Destructor: Ensures memory is freed when the stack object goes out of scope.

// This implementation is efficient and dynamically manages memory for the stack.