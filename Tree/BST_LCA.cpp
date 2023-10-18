//https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/submissions/code/337508781

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
  
    Node *lca(Node *root, int v1,int v2) {
        if(root == NULL){
            return NULL;
        }
		if(root->data == v1 || root->data == v2){
            return root;// ektar niche jodi arekta thake tau eikhanei handle hosse
            //2 ta alada alada jaigai thakleu problem hobe na
        }
        Node* leftLCA = lca(root->left, v1, v2);
        Node* rightLCA = lca(root->right, v1, v2);
        
        if(leftLCA && rightLCA){
            return root;
        }
        else if(rightLCA==NULL){ // right theke na paoa mane right to hobei na ei root o hobe na
            return leftLCA;
        }
        else
            return rightLCA;
    }

