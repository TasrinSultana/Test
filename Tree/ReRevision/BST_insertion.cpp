//https://www.hackerrank.com/challenges/binary-search-tree-insertion/submissions/code/337484584 agerbarer
// apna college 107(BST- binary search tree introduction)
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

void preOrder(node* root){ //root left right
    if(root==NULL) return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

node*  insert_BST(node* root, int n){
    if(root==NULL){
        root = new node(n);
        // shob jaigai to jaina jei NULL position e jai sheikhanei node ta insert hoy
        return root;
    }
    //notun ekta node insert hoye jokhon return hoy tokhon oi node ke hoy right nahoy left node hishebe add kore neoa lage
    // add korei neoa hosse "root->right =.." eita diye
    if(root->val > n){
        root->left = insert_BST(root->left, n);
    }
    else{
        root->right = insert_BST(root->right, n);
    }
    return root;
}

int main(){
    node* root = NULL;
    int n = 1;
    root = insert_BST(root, n);
    n = 2;
    root = insert_BST(root, n);
    n = 3;
    root = insert_BST(root, n);
    preOrder(root);
    cout << endl;
}