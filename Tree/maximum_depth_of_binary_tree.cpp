// apnna college
// 95(Level Order Traversal , Sum at Kth Level In Binary Tree)
// video dekhe creating_tree_using_nodes_traversal.cpp code e
// level order traversal ke ektu modify korei hoye gese
// https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/904059497/
// total node count eikhanei postorder e ase 
// ashole jekono traversal ei total count e kora jabe
// count_and_sum_of_binary_tree.cpp eu alada program ase

#include<iostream>
#include<queue>
using namespace std;

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

int maximum_depth_of_binary_tree(node* root){ 
    if(root == NULL)
        return -1;
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    while(!q.empty()){
        node* nd = q.front();
        q.pop();
        if(nd){
            if(nd->left){ // left jodi thake, na thakle null hobe ja 0 so if true hobena
                q.push(nd->left);
            }
            if(nd->right){
                q.push(nd->right);
            }
        }
        else{
            if(!q.empty()){
                q.push(NULL);
                level++;
            }
        }
    }
    return level;
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    /*
                1
          2           3

        4    5      6    7     
    */

    cout << "Maximum depth of the binary tree: ";
    cout << maximum_depth_of_binary_tree(root) << endl; // root is 0 level

    return 0;
}