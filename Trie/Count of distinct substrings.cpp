// https://practice.geeksforgeeks.org/problems/count-of-distinct-substrings/1
class Trie{
    public:
        Trie* child[26];
        bool isEnd=false;
};
int countDistinctSubstring(string str)
{
    //Your code here
    int ans=0;
    Trie* root=new Trie();
    for(int i=0;i<str.size();i++){
        Trie* curr=root;
        for(int j=i;j<str.size();j++){
            int ind=str[j]-'a';
            if(curr->child[ind]==NULL){
                ans++;
                curr->child[ind]=new Trie();
                curr->isEnd=true;
            }
            else if(curr->isEnd==false){
                ans++;
                curr->isEnd=true;
            }
            curr=curr->child[ind];
        }
    }
    return ans+1;
}