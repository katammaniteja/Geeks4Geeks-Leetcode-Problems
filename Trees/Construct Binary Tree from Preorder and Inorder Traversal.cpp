class Solution {
public:
    int key=0;
    TreeNode* construct(vector<int>&in,vector<int>&pre,int start,int end){
        if(start>end) return NULL;
        TreeNode* root=new TreeNode(pre[key++]);
        int index;
        for(index=start;index<=end;index++){
            if(in[index]==root->val) break;
        }
        root->left=construct(in,pre,start,index-1);
        root->right=construct(in,pre,index+1,end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return construct(inorder,preorder,0,preorder.size()-1);
    }
};