#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

void createDoublyLL(Node *&head , int value){
    Node *newnode = new Node(value);

    if(head == nullptr){
        head = newnode;
        return;
    }

    Node *temp = head;
    
    while (temp->next != nullptr)
    {
        temp = temp->next;

        /* code */
    }
    temp->next = newnode;
    newnode->prev = temp;
    
}

Node *get(Node *head, int index){
    int counter = 0;
    Node *temp = head;
    while(temp!= nullptr && counter < index){
        temp = temp->next;
        counter ++;

    }
    if(temp == nullptr) return nullptr;

    return temp;
}

void display(Node* head){
    Node *temp = head;
    cout<<"linked list is: ";

    while (temp != nullptr)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
        /* code */
    }
    cout<<endl;
}

int main(){
    Node *head;
    head = nullptr;
    createDoublyLL(head,4);
    createDoublyLL(head,5);
    createDoublyLL(head,6);
    createDoublyLL(head,8);

    Node *result = get(head,3);
    cout<<"the value u asked for: "<<result->data<<endl;


    display(head);

    return 0;
}
