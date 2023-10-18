#include<iostream>
using namespace std;
// count sum duitai jekono traversal er moto korei kora jabe
// khub shohoj e, tau evabeu korlam

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int n){
        data = n;
        left = NULL;
        right = NULL;
    }
};

int node_count(node* root){
    if(root == NULL){
        return 0;
    }
    return node_count(root->left) + node_count(root->right) + 1; 
}

int sum_of_all_node(node* root){
    if(root==NULL){
        return 0;
    }
    return sum_of_all_node(root->left)+sum_of_all_node(root->right)+ root->data;
}
    /*
                1
                
          2           3

        4    5      6    7     
    */

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << "Total node in tree: ";
    cout << node_count(root) << endl << endl;

    cout << "Total sum in tree: ";
    cout<< sum_of_all_node(root) << endl;
}