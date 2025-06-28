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
Node *reverselist(Node *head)
{
    Node  *current = head;
    Node *prev = nullptr;
    Node *next ;
    while (current!= nullptr)
    {
        next=current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    return prev;

}

void printnode(Node *head)
{
    while (head!=nullptr)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
    
}

int main()
{
    Node *head = nullptr;

    insertAtEnd(head,20);
    insertAtEnd(head,30);
    insertAtEnd(head,90);
    insertAtEnd(head,80);
    insertAtEnd(head,40);
    insertAtEnd(head,60);
    printnode(head);
    head = reverselist(head);
    printnode(head);

    return 0;

}