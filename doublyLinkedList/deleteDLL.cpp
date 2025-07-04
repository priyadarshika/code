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

void deleteDoublyLL(Node *&head, int value){
    if(head == nullptr) return ;

    Node *temp = head;

    if(temp->data == value){
        head = head->next;
        if(head->next == nullptr){
            head->prev = nullptr;
        }
        delete temp;
        cout<<"there was one node and its deleted"<<endl;
        return;
    }
    while(temp->next!= nullptr && temp->data != value){
        temp = temp->next;
    }

    if(temp->next!= nullptr){
        temp->next->prev = temp->prev;
    }

    if (temp->prev!= nullptr)
    {
        temp->prev->next = temp->next;
        /* code */
    }
    delete temp;
    cout<<"the node is deleted"<<value<<endl;

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

    display(head);

    deleteDoublyLL(head,5);

    display(head);

    return 0;
}
