// https://leetcode.com/problems/house-robber-iii/
class Solution {
public:
    pair<int,int> helper(TreeNode* root) {
        if(!root) return {0,0};
        auto l=helper(root->left);
        auto r=helper(root->right);
        int inc=l.second+r.second+root->val;
        int exc=max(l.first,l.second)+max(r.first,r.second);
        return {inc,exc};
    }

    int rob(TreeNode* root){
        pair<int,int>a=helper(root);
        cout<<a.first<<" "<<a.second;
        return max(a.first,a.second);
    }
};