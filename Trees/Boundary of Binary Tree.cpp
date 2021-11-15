class Solution {
public:
    void leftNodes(Node* root,vector<int>&v){
        if(root->left!=NULL) {
            v.push_back(root->data);
            leftNodes(root->left,v);
        }
        else if(root->right!=NULL){
            v.push_back(root->data);
            leftNodes(root->right,v);
        }
    }
    void leaf(Node* root,vector<int>&v){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            v.push_back(root->data);
            return;
        }
        leaf(root->left,v);
        leaf(root->right,v);
    }
    void rightNodes(Node* root,vector<int>&v){
        if(root->right!=NULL) {
            rightNodes(root->right,v);
            v.push_back(root->data);
        }
        else if(root->left!=NULL){
            rightNodes(root->left,v);
            v.push_back(root->data);
        }
    }
    vector <int> printBoundary(Node *root){
        vector<int>v;
        v.push_back(root->data);
        if(root->left!=NULL) {
            leftNodes(root->left,v);
            leaf(root->left,v);
        }
        if(root->right!=NULL){
            leaf(root->right,v);
            rightNodes(root->right,v);
        }
        return v;
    }
};