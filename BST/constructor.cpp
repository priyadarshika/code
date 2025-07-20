#include <iostream>
using namespace std;

class Node{
    public:
    int value;
    Node *left;
    Node *right;

    Node(int val){
        this->value = val;
        left = nullptr;
        right = nullptr;
    }
};

class binarySearchtree{
    public:
    Node *root;

    public:
    binarySearchtree(){
        root = nullptr;
    }

    void destroy(Node *currentNode){
        if(currentNode->left) destroy(currentNode->left);
        if(currentNode->right) destroy(currentNode->right);
        delete currentNode;

    }

    ~binarySearchtree() {destroy (root);}

    bool insert(int value){
        Node *newNode = new Node(value);
        if(root == nullptr){
            root = newNode;
            return true;
        }

        Node *temp = root;
        while(true){
            if(newNode->value == temp->value)
            return false;

            if(temp->value < newNode->value){
                if(temp->left == nullptr){
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left;
            }else{
                if(temp->right == nullptr){
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            }
        }
    }
};

int main(){
    binarySearchtree* myBST = new binarySearchtree();

    myBST->insert(2);
    myBST->insert(1);
    myBST->insert(3);

    cout << "Root: " << myBST->root->value;
    cout << "\n\nRoot->Left: " << myBST->root->left->value;
    cout << "\n\nRoot->Right: " << myBST->root->right->value<<endl;
}