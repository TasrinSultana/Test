#include<iostream>
#include<queue>
using namespace std;
// apna college 98(sum replacement in binary tree)- video onujaye na kore ami nijei koresi
// amar mone hosse thik e hoyse

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

int sum_replace(node* &root){
    if(root == NULL) return 0;
    root->val = sum_replace(root->left) + sum_replace(root->right) + root->val;
    return root->val;
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

    preOrder(root);
    cout << endl;
    cout << sum_replace(root) << endl;
    preOrder(root);
}
/*
        1
    2       3
 4     5  6    7
  9          10
*/