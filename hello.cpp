#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Function to display the linked list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Creating nodes
    Node* head = createNode(10);
    Node* second = createNode(20);
    Node* third = createNode(30);

    // Linking nodes
    head->next = second;
    second->next = third;

    // Displaying the linked list
    cout << "Linked List: ";
    displayList(head);

    return 0;
}
