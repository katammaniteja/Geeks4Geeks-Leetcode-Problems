// https://binarysearch.com/problems/Cutting-Binary-Search-Tree
Tree* solve(Tree* root, int lo, int hi) {
    if(root==NULL) return NULL;
    if(root->val<lo){
        return solve(root->right,lo,hi);
    }
    else if(root->val>hi){
    return solve(root->left,lo,hi);
    }
    else{
        root->left=solve(root->left,lo,hi);
        root->right=solve(root->right,lo,hi);
        return root;
    }
}