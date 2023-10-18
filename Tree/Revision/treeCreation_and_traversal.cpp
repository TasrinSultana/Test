#include<iostream>
using namespace std;

class node{
    public:// constructor o public nahole baire theke access kora jai na
    // left right o public na thakle root->left ba root->right eivabe access paoa jabe na
    int val;
    node* left;
    node* right;
    node(int n){
        val = n;
        left = NULL;
        right = NULL;
    }
};

void preOrder(node* root){
    if(root == NULL){
        return;
    }
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

void InOrder(node* root){
    if(root == NULL){
        return;
    }
    InOrder(root->left);
    cout << root->val << " ";
    InOrder(root->right);
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    
    //eivabe abar name deoa jai
    node* rootRight = root->right;

    rootRight->left = new node(6);
    rootRight->right = new node(7);
    
    cout << "PreOrder: ";
    preOrder(root);
    
    cout << endl << "PostOrder: ";
    postOrder(root);  

    cout << endl << "InOrder: ";
    InOrder(root);
}

/*
        1
    2       3
 4     5  6    7
*/