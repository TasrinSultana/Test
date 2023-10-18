// apna college 96(count and sum of nodes in binary tree)
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

int countNode(node* root){
    if(root == NULL) return 0;
    return countNode(root->left) + countNode(root->right) + 1;
}

int sum_of_tree(node* root){
    if(root == NULL) return 0;
    return sum_of_tree(root->left) + sum_of_tree(root->right) + root->val;
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

    cout << countNode(root) << endl;
    cout << sum_of_tree(root) << endl;
}
/*
        1
    2       3
 4     5  6    7
  9          10
*/