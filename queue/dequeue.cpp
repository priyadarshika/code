#include <iostream>
using namespace std;

class Node{
    public:
    int value;
    Node *next;

    Node(int value){
        this->value =  value;
        next = nullptr;
    }
};

class queue{
    private:
    Node *first;
    Node *last;
    int length;

    public:
    queue (int value){
        Node *newnode = new Node(value);
        first = newnode;
        last = newnode;
        length = 1;
    }

void print(){
    Node *temp = first;
    while(temp){
        cout<<temp->value<<endl;
        temp = temp->next;
    }
}

void enqueue(int value){
    Node *newnode = new Node(value);
    if(length == 0){
        first = newnode;
        last = newnode;
        length = 1;
    }
    else{
        last->next = newnode;
        last = newnode;
        
        
    }
    length++;
}

int deqeueu(){
    if(length == 0) return -1;
    Node *temp = first;
    int dequeueValue = first->value;
    if(length == 1){
        first = nullptr;
        last = nullptr;

    }
    else {
        first = first->next;

    }
    delete temp;
    length--;
    return dequeueValue;
}

// void getfirst()
// {
//     cout<<"first value: "<<first->value<<endl;
// }

// void getlast(){
//     cout<<"last value: "<<last->value<<endl;
// }

void getlength(){
    cout<<"length: "<<length<<endl;
}

};

int main(){
    queue *myqueue = new queue(7); 

    myqueue->enqueue(4);
    myqueue->enqueue(6);

    cout<<"the deqeueu value is : "<<myqueue->deqeueu()<<endl;

    // myqueue->getfirst();
    // myqueue->getlast();
    myqueue->getlength();

    myqueue->print();
}