// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1#
class Solution
{
    public: 
    Node *prev=NULL;
    Node * bToDLL(Node *root)
    {
        if(root==NULL) return root;
        Node* head=bToDLL(root->left);
        if(prev==NULL) head=root;
        else{
            root->left=prev;
            prev->right=root;
        }
        prev=root;
        bToDLL(root->right);
        return head;
        
    }
};