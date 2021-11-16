// https://leetcode.com/problems/count-complete-tree-nodes/

// Given the root of a complete binary tree, return the number of the nodes in the tree.
// According to Wikipedia, every level, except possibly the last, is completely filled 
// in a complete binary tree, and all nodes in the last level are as far left as possible. 
// It can have between 1 and 2h nodes inclusive at the last level h.
// Design an algorithm that runs in less than O(n) time complexity.

class Solution {
public:
    int countNodes(TreeNode* root) {
        int lh=0,rh=0;
        TreeNode* curr=root;
        while(curr!=NULL){
            lh++;
            curr=curr->left;
        }
        curr=root;
        while(curr!=NULL){
            rh++;
            curr=curr->right;
        }
        if(lh==rh) return pow(2,lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};