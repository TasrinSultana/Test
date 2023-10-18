/*
apna college
1(Binary tree er introduction and creation-I use class), 92(preorder,inorder,postorder traversal by recursion),
95(level order traversal & sum at kth level- eita shudhu nai eikhane)
*/
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
void inOrder(node* root){//left root right
    if(root==NULL) return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}
void postOrder(node* root){//left right root
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}
// er NULL push kore kore kortam ja ektu jhamelar tobe valo vabei partam
// eikhane NULL sara korsi, eivabei simple, age eita mathai asheni
void levelOrder(node* root){// bfs er kaj holo level ordering
    if(root == NULL){
        return;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; i++){
            node* fr_node = q.front();
            q.pop();
            cout << fr_node->val << " ";
            if(fr_node->left){
                q.push(fr_node->left);
            }
            if(fr_node->right){
                q.push(fr_node->right);
            }
        }
        cout << endl;
    }
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
    inOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;

    levelOrder(root);
}
/*
        1
    2       3
 4     5  6    7
  9          10
*/