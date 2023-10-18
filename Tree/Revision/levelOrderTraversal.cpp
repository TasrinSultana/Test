// level order traversal preorder inorder postorder er moto recursion diye
// korte parbona karon recursion je dikei jai ekdom tar depth porjonto jai
// kintu level order traversal e depth jaoa jabe na level by level jete hobe

// level order traversal holo breadth first search(BFS)
#include<iostream>
#include<queue>
using namespace std;

class node{
    public:// constructor o public nahole baire theke access kora jai na
    // left right o public na thakle root->left ba root->right eivabe access paoa jabe na
    // val public na thakle root->val eirokom access paoa jabe 
    // variable public na korle alada public function banate hobe(so ei jhamela keno korte jabo)  
    int val;
    node* left;
    node* right;
    node(int n){
        val = n;
        left = NULL;
        right = NULL;
    }
};

void levelOrederTraversal(node* root){
    if(root==NULL){
        return; // tree exist e kore na
    }

    queue<node*>q; // int er queue banaye lav nai karon left right er track pabo na
    q.push(root);
    q.push(NULL);//indication of level zero shesh
    cout << "This is level === 0" << endl;
    int level = 0;
    while(!q.empty()){
        node* front = q.front();
        q.pop();
        if(front==NULL){
            if(!q.empty()){
                q.push(NULL);
                level++;
                cout << endl <<"This is level === " << level << endl;
            }
        }
        else{
            cout << front->val << " ";
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
    }
}
void levelOrder(node* root){// eikhane NULL sara korsi, eivabei simple, age eita mathai asheni
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
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    
    //eivabe abar name deoa jai
    node* rootRight = root->right;

    rootRight->left = new node(6);
    rootRight->right = new node(7);
    
    cout << endl << " levelOrederTraversal: " << endl;
    levelOrederTraversal(root);
}

/*
        1
    2       3
 4     5  6    7
*/