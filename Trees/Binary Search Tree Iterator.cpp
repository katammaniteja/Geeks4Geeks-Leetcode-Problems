// https://leetcode.com/problems/binary-search-tree-iterator/
class BSTIterator {
public:
    stack<TreeNode*>s;
    BSTIterator(TreeNode* root) {
        Insert(root);
    }
    void Insert(TreeNode* root){
        for(TreeNode* temp=root;temp!=NULL;){
            s.push(temp);
            temp=temp->left;
        }
    }
    int next() {
        TreeNode* temp=s.top();
        s.pop();
        if(temp->right){
            Insert(temp->right);
        }
        return temp->val;
    }
    
    bool hasNext() {
        if(s.size()) return true;
        return false;
    }
};