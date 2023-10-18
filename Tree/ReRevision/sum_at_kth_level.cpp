
#include<iostream>
#include<queue>
using namespace std;
int sum;

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

void preOrder(node* root, int k, int level){ //root left right
    if(root==NULL) return;
    if(k==level)
    sum += root->val;
    preOrder(root->left, k, level+1);
    preOrder(root->right, k, level+1);
}


// er NULL push kore kore kortam ja ektu jhamelar tobe valo vabei partam
// eikhane NULL sara korsi, eivabei simple, age eita mathai asheni
int levelOrder(node* root, int k){// bfs er kaj holo level ordering
    if(root == NULL){
        return -1;// problem statement onujaye ki kora jai dekhte hobe
    }
    queue<node*>q;
    q.push(root);
    int level = 0;
    int sum = 0;
    while(!q.empty()){
        level++;
        if(level > k)
        break;
        int n = q.size();
        for(int i = 0; i < n; i++){
            node* fr_node = q.front();
            q.pop();
            if(level == k)
                sum += fr_node->val;
            if(fr_node->left){
                q.push(fr_node->left);
            }
            if(fr_node->right){
                q.push(fr_node->right);
            }
        }
    }
    return sum;
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

    int level;
    cin >> level;
    cout << levelOrder(root, level) << endl;
    sum = 0;
    preOrder(root, level, 1);
    cout << sum << endl;
}
/*
        1
    2       3
 4     5  6    7
  9          10
*/