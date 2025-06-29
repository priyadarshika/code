#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void insertAtEnd(Node *&head, int value) {
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertAtPostion(Node *&head, int value, int pos) {
    Node *newNode = new Node();
    newNode->data = value;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Out of bound" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteByValue(Node *&head, int value) {
    if (head == nullptr) return;

    if (head->data == value) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }

    if (current->next == nullptr) return;

    Node *temp = current->next;
    current->next = current->next->next;
    delete temp;
}

Node *findMiddleNode(Node *head)
{
    if(!head) return nullptr;

    Node* fast = head;
    Node *slow = head;

    while (fast!=nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;

    
}

// void deleteByPosition(Node *&head, int pos) {
//     if (head == nullptr || pos < 1) return;

//     if (pos == 1) {
//         Node *temp = head;
//         head = head->next;
//         delete temp;
//         return;
//     }

//     Node *current = head;
//     for (int i = 1; current != nullptr && i < pos - 1; i++) {
//         current = current->next;
//     }

//     if (current == nullptr || current->next == nullptr) return;

//     Node *temp = current->next;
//     current->next = current->next->next;
//     delete temp;
// }

void printnode(Node *head) {
    while (head != nullptr) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node *head = nullptr;

    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 80);
    insertAtPostion(head, 90, 3);
    insertAtPostion(head, 40, 2);  // List: 20->40->30->NULL

    printnode(head);

    Node *middle = findMiddleNode(head);
    cout<< middle->data<<endl;

    // deleteByValue(head, 20);       // Deletes 20, List: 40->30->NULL
    // deleteByPosition(head, 2);     // Deletes node at pos 2 (i.e., 30)

    // printnode(head);               // Final: 40->NULL

    return 0;
}