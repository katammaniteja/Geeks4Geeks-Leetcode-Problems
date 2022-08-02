// https://practice.geeksforgeeks.org/problems/maximum-xor-of-two-numbers-in-an-array/1
class Solution
{
    public:class Trie{
        public:Trie* child[2];
    };
    Trie* root=new Trie();
    void insert(int n){
        Trie* curr=root;
        for(int i=31;i>=0;i--){
            int bit=(n>>i)&1;
            if(curr->child[bit]==NULL) curr->child[bit]=new Trie();
            curr=curr->child[bit];
        }
    }
    int getMax(int n){
        Trie* curr=root;
        int ans=0;
        for(int i=31;i>=0;i--){
            int bit=(n>>i)&1;
            if(curr->child[1-bit]!=NULL){
                ans=ans+pow(2,i);
                curr=curr->child[1-bit];
            }
            else curr=curr->child[bit];
        }
        return ans;
    }
    int max_xor(int arr[] , int n)
    {
        for(int i=0;i<n;i++){
            insert(arr[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,getMax(arr[i]));
        }
        return ans;
    }
};