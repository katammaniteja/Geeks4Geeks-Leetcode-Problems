// Given the root of a binary tree, determine if it is a valid binary search tree (BST).
class Solution {
public:
    bool help(TreeNode* root,int64_t mi,int64_t ma){
        if(root==NULL) return true;
        if(root->val>=ma || root->val<=mi) return false;
        return help(root->left,mi,root->val)&&help(root->right,root->val,ma);
    }
    bool isValidBST(TreeNode* root) {
        return help(root,INT64_MIN,INT64_MAX);
    }
};