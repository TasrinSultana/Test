// apna college 105(Lowest Common Ancestor in binary tree)
//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/ agerbarer
#include<iostream>
#include<queue>
using namespace std;

class node{
    public:// variable and constructor 2ta public korte hobe karon 2ta kei baire theke access kora lagbe
    // left right o public na thakle root->left ba root->right eivabe access paoa jabe na
    // val public na thakle root->val eirokom access paoa jabe 
    // variable public na korle alada public function banate hobe(so ei jhamela keno korte jabo) 
    int val;
    node* left;
    node* right;

    node(int data){//*** constructor private hole kaj kore na
        val = data;
        left = NULL;
        right = NULL;
    }

};
// assuming that nod1 and node2 will be exist in tree
node* find_lca(node* root, node* node1, node* node2){
    if(root==NULL){
        return NULL;
    }
    if(root == node1 || root == node2){
        return root;
    }
    node* l = find_lca(root->left, node1, node2);
    node* r = find_lca(root->right, node1, node2);

    if(l && r){
        return root;
    }
    else if(l){
        return l;
    }
    return r;
}

int main(){
    node* root = new node(1);
    root->left = new node(2);// root create houar time e tar left o create hoye ase 
    node* root_right = new node(3);// notun vabe node create korsi
    root->right = root_right;// tarpor oi node er address ke root->right store korsi, so oi node root er right node holo 
    node* root_left = root->left;//node tar notun name dilam

    root_left->left = new node(4);
    root_left->right = new node(5);
    root_right->left = new node(6);
    root_right->right = new node(7);

    root_left->left->right = new node(9);
    root_right->right->left = new node(10);

    node* node1 = root_left->right;
    node* node2 = root_left->left->right;

    node* lca = find_lca(root, node1, node2);
    cout << lca->val << endl;
}
/*
        1
    2       3
 4     5  6    7
  9          10
*/