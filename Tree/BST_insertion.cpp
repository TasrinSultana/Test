//https://www.hackerrank.com/challenges/binary-search-tree-insertion/submissions/code/337484584
// apna college 107(BST- binary search tree introduction)

/*
Node is defined as 

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node * insert(Node * root, int data) {
        if(root == NULL){
            root = new Node(data); // new always soto hater hoy
            // shob jaigai to jaina jei NULL position e jai sheikhanei node ta insert hoy
            return root;
        }
        if(data > root->data){
            //notun ekta node insert hoye jokhon return hoy tokhon oi node ke hoy right nahoy left node hishebe add kore neoa lage
            // add korei neoa hosse "root->right =.." eita diye
            root->right = insert(root->right, data);
        }
        else{
            root-> left = insert(root->left, data);
        }

        return root;
    }

