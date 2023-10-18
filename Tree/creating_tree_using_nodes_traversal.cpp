//apnna college
//91(Binary tree er introduction and creation-I use class), 
//92(preorder,inorder,postorder traversal by recursion),
// 95(Level Order Traversal , Sum at Kth Level In Binary Tree)
#include<iostream>
#include<queue>
using namespace std;
int cnt;

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

void preorder(node* root){
    if(root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(node* root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
    cnt++;
}

void level_order_traversal(node* root){ // it should be revised frequently
    if(root == NULL)
        return;
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* nd = q.front();
        q.pop();
        if(nd){
            cout << nd->data << " ";
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
            }
        }
    }
}

int sum_at_kth_level(node* root, int k){
    if(root==NULL){
        return -1; // assuming negative can't be member
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    int sum=0, level = 0;
    while(!q.empty()){
        node* nd = q.front();
        q.pop();
        if(nd == NULL){
            if(!q.empty()){
                level++;
                q.push(NULL);
            }

        }
        else{
            if(level == k){
                sum += nd->data;
            }
            if(nd->left){
                q.push(nd->left);
            }
            if(nd->right){
                q.push(nd->right);
            }
        }
    }
    return sum;
}

//https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/submissions/904049638/
//temon important na, jei level e maximum ase shei level er number return korbe
int maximum_sum_level(node* root){
    if(root==NULL){
        return -1; // assuming negative can't be member
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    int sum=0, level = 0, max_sum = INT32_MIN, ans_level = 0; // INT64_MIN overflow warning disse
    // max_sum int var tai hoyto, 64 dorkar o nai obossho emnni likhlam
    while(!q.empty()){
        node* nd = q.front();
        q.pop();
        if(nd == NULL){
            if(max_sum<sum){
                max_sum = sum;
                ans_level = level;
            }
            sum = 0;
            if(!q.empty()){
                level++;
                q.push(NULL);
            }

        }
        else{
            sum += nd->data;
            if(nd->left){
                q.push(nd->left);
            }
            if(nd->right){
                q.push(nd->right);
            }
        }
    }
    return ans_level;
}

int height_of_tree(node* root){
    if(root == NULL){
        return -1;
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    int level = 1;
    while(!q.empty()){
        node* nd = q.front();
        q.pop();
        if(nd){
            if(nd->left)
                q.push(nd->left);
            if(nd->right)
                q.push(nd->right);
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

    // Traversal
    cout << endl << endl;

    cout << "PreOrder:  ";
    preorder(root);
    cout << endl << endl;

    cout << "InOrder:   ";
    inorder(root);
    cout << endl << endl;

    cout << "PostOrder: ";
    postorder(root);
    cout << endl << endl;
    cout << "Cnt " << cnt << endl;

    cout << "level_order_traversal: ";
    level_order_traversal(root);
    cout << endl << endl;

    cout << sum_at_kth_level(root,0)<< endl;
    cout << sum_at_kth_level(root,1)<< endl;
    cout << sum_at_kth_level(root,2)<< endl;

    cout<< endl << "Maximum sum's level: ";
    cout << maximum_sum_level(root) << endl;

    cout << "height of tree: ";
    int h = height_of_tree(root);
    cout << h << endl;


    return 0;
}