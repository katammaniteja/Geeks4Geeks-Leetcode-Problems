// https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1
// Given a Binary Search Tree and a node value X. Delete 
// the node with the given value X from the BST. If no 
// node with value x exists, then do not make any change. 
Node* getSuccessor(Node* root){
    while(root->left!=NULL) root=root->left;
    return root;
}
Node* deleteNode(Node* root, int key) {
    if(root==NULL) return root;
    else if(root->data >key){
        root->left=deleteNode(root->left,key);
    }
    else if(root->data <key){
        root->right=deleteNode(root->right,key);
    }
    else if(root->data==key){
        if(root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else{
            Node* temp=getSuccessor(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
    }
    return root;
}