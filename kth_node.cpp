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

void  insertAtPostion(Node *head, int value, int pos)
{
    Node *newNode = new Node();
    newNode->data = value;

    if(pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    } Node *temp = head;

    for(int i=1; i<pos-1 && temp!= nullptr; i++)
    {
        temp = temp->next;

    }
    
    if(temp == nullptr)
    {
        cout<<"out of bound"<<endl;
        delete newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;


}

// void deleteByValue(Node *head, int value)
// {
//     if(head == nullptr) return;

//     if(head->data == value)
//     {
//         Node *temp = head;
//         head = head->next;
//         delete temp;
//         return;
//     }
//     Node *current =head;
//     while (current -> next!= nullptr && current->next->data!= value)
//     {
//         current = current->next;
//     }

//     if(current->next == nullptr) return;

//     Node *temp = current->next;
//     current->next = current->next->next;
//     delete temp;
    
// }

Node *findKthNode(Node *head, int k)
{
    Node *current = head;
    int count =1;

    while (current != nullptr)
    {
        if (count == k)
        {
            return current;

        }

        current = current ->next;
        count++;
        
    }
    return nullptr;
    {
        /* code */
    }
    
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

    int k;

    k=3;
     

    insertAtEnd(head,20);
    insertAtEnd(head,30);
    insertAtPostion(head,40,2);


    printnode(head);
    Node *Kthnode = findKthNode(head , k);

    if (Kthnode)
    {
        cout<<"the kth value is = "<<Kthnode->data<<endl;
    }
    else
    cout<<"the given value does not exist";
    // deleteByValue(head,20);
    // printnode(head);

    return 0;

}