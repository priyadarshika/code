#include <iostream>
using namespace std;

class Node{
    public:
    int value;
    Node *next;
    Node(int value){
        this->value = value;
        next = nullptr;
    }
};

class stack{
    private: 
    Node *top;
    int height;

    public:
    stack(int value){
        Node *newnode = new Node(value);
        top = newnode;
        height = 1;
    }

    ~stack(){
        Node *temp = top;
        while (top){
            top = top->next;
            delete temp;
            temp = top;
        }
    }

    void printstack(){
        Node *temp = top;
        while(temp){
            cout<< temp->value <<endl;
            temp = temp->next;

        }
    }

    void gettop(){
        cout<<"top: "<< top->value <<endl;
    }

    void getheight(){
        cout<<"height"<<height<<endl;
    }
};

int main(){
    stack *mystack = new stack(4);
    mystack->gettop();
    mystack->getheight();
    mystack->printstack();

}