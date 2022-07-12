// https://leetcode.com/problems/word-break-ii/
class Solution {
public:
    class Trie{
        public:
        Trie* child[26];
        bool isEnd=false;
    };
    Trie* root=new Trie();
    void addWord(string &str){
        Trie* curr=root;
        for(char &ch:str){
            int ind=ch-'a';
            if(curr->child[ind]==NULL) curr->child[ind]=new Trie();
            curr=curr->child[ind];
        }
        curr->isEnd=true;
    }
    void helper(vector<string>&ans,int ind,string s,string temp){
        if(ind==s.size()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        Trie* curr=root;
        for(int i=ind;i<s.size();i++){
            int x=s[i]-'a';
            if(curr->child[x]==NULL) return;
            curr=curr->child[x];
            if(curr->isEnd){
                helper(ans,i+1,s,temp+s.substr(ind,i-ind+1)+" ");
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string &str:wordDict) addWord(str);
        vector<string>ans;
        helper(ans,0,s,"");
        return ans;
    }
};