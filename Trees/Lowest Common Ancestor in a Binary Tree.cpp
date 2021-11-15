// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1#

// Given a Binary Tree with all unique values and two nodes value n1 and n2. 
// The task is to find the lowest common ancestor of the given two nodes. We 
// may assume that either both n1 and n2 are present in the tree or none of 
// them is present. 

class Solution{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int p ,int q ){
        if(root==NULL || root->data==p || root->data==q) return root;
        Node* left=lca(root->left,p,q);
        Node* right=lca(root->right,p,q);
        if(left==NULL) return right;
        if(right==NULL) return left;
        return root;
    }
};