// You are given the root of a binary search tree (BST), where the 
// values of exactly two nodes of the tree were swapped by 
// mistake. Recover the tree without changing its structure.
class Solution {
public:
    TreeNode* prev=NULL,*first=NULL,*second=NULL;
    void helper(TreeNode* root){
        if(root==NULL) return;
        helper(root->left);
        if(prev!=NULL && root->val<prev->val){
            if(first==NULL) first=prev;
            second=root;
        }
        prev=root;
        helper(root->right);
        
    }
    void recoverTree(  TreeNode* root )
    {
        helper(root);
        swap(first->val,second->val);
    }
};