// eita run korar agei vscode e problem hoise
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    node* root_left = root->left;
    node* root_right = root->right;

    node* test = new node(5);
    root_left->left = test;
    root_left->right = new node(6);

    root_right->left = new node(7);
    root_right->right = new node(8); 
}