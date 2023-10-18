//diameter-O(n^2) 
//apna college 97(Height & diameter{O(n^2)} in BT)
//https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree
// height ke maximum depth o bole https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/
// https://leetcode.com/problems/diameter-of-binary-tree/
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
/*
        1-----------height 4
    2       3-------height 3
 4     5  6    7----height 2
  9          10 ----height 1
*/
//tobe eikhane root er height borong left ar right er height ber kora hosse jar fole kahini thik thakse
//er age preOrder diye korsilam, tobe eita beshi simple
int height(node* root){
    if(root == NULL) return 0;
    return max(height(root->left), height(root->right)) + 1;
}

int diameter(node* root){
    if(root == NULL) return 0;
    int with_root = height(root->left) + height(root->right);
    int l = diameter(root->left);
    int r = diameter(root->right);
    return max(with_root, max(l,r));
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

    cout << height(root) << endl;
    cout << diameter(root) << endl;
}
