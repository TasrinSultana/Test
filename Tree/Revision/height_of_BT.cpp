// best approach, reRevision er time e koresi cpp/Tree/ReRevision/height_and_diameter_BT.cpp
//https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree/submissions/code/337478413

// er agey level order traversal kore height(maximum depth) ber kortam
// eibar preOrder diye korlam, jekono traversal diyei kora jabe ashole

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int mxlevel = -1; // level nile kaj hobe na karon function call er time automatic level overwrite hoye jabe
    void preOrder(Node* root, int level){
        if(root==NULL){
            mxlevel = max(mxlevel, level-1);
            return;
        }
        preOrder(root->left, level+1);
        preOrder(root->right, level+1);
    }
    int height(Node* root) {
        preOrder(root, 0);
        return mxlevel;
    }

