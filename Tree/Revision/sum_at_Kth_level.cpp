#include<iostream>
#include<queue>
using namespace std;

int k; // level number whose sum we want
int sum = 0;

class node{
    public:// constructor o public nahole baire theke access kora jai na
    // left right o public na thakle root->left ba root->right eivabe access paoa jabe na
    int val;
    node* left;
    node* right;
    node(int n){
        val = n;
        left = NULL;
        right = NULL;
    }
};

void Sum_by_preOrder(node* root, int level){
    if(root == NULL){
        return;
    }
    if(level == k){
        sum += root->val;
    }
    Sum_by_preOrder(root->left, level+1);
    Sum_by_preOrder(root->right, level+1);
}

void Sum_by_levelOrederTraversal(node* root, int k){
    if(root==NULL){
        return; // tree exist e kore na
    }

    queue<node*>q; // int er queue banaye lav nai karon left right er track pabo na
    q.push(root);
    q.push(NULL);//indication of level zero shesh
    //cout << "This is level === 0" << endl;
    int level = 0;
    while(!q.empty()){
        node* front = q.front();
        q.pop();
        if(front==NULL){
            if(!q.empty()){
                q.push(NULL);
                level++;
                //cout << endl <<"This is level === " << level << endl;
            }
        }
        else{
            //cout << front->val << " ";
            if(level == k)
                sum += front->val;
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
    }
}


int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    
    //eivabe abar name deoa jai
    node* rootRight = root->right;

    rootRight->left = new node(6);
    rootRight->right = new node(7);

    cin >> k;

    
    cout << "PreOrder Sum at " << k << "th level: ";
    Sum_by_preOrder(root, 0);
    cout << sum << endl;

    sum = 0;
    cout << "levelOrder Sum at " << k << "th level: ";
    Sum_by_levelOrederTraversal(root, k);
    cout << sum << endl;
    
}

/*
        1
    2       3
 4     5  6    7
*/