// https://practice.geeksforgeeks.org/problems/print-common-nodes-in-bst/1
// Given two Binary Search Trees. Find the nodes that are common 
// in both of them, ie- find the intersection of the two BSTs.
class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
        vector<int>v;
        stack<Node*>s1,s2;
        while(1){
            if(root1){
                s1.push(root1);
                root1=root1->left;
            }
            else if(root2){
                s2.push(root2);
                root2=root2->left;
            }
            else if(s1.size() && s2.size()){
                root1=s1.top();
                root2=s2.top();
                if(root1->data==root2->data) {
                    v.push_back(root1->data);
                    s1.pop();
                    s2.pop();
                    root1=root1->right;
                    root2=root2->right;
                }
                else if(root1->data<root2->data){
                    s1.pop();
                    root1=root1->right;
                    root2=NULL;
                }
                else{
                    s2.pop();
                    root2=root2->right;
                    root1=NULL;
                }
            }
            else break;
        }
        return v;
    }
};
