#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void insertAtEnd(Node *&head, int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if(head == nullptr){
         head = newNode;
    return;
    }

    Node *temp = head;
    while (temp->next!=nullptr)
    {
        temp = temp->next;
    }
    
    temp->next = newNode;

}

void printnode(Node *head)
{
    while (head!=nullptr)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL";
    
}

int main()
{
    Node *head;

    insertAtEnd(head,20);
    insertAtEnd(head,30);
    printnode(head);

    return 0;

}