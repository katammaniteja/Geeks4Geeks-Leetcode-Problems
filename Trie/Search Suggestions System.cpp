// https://leetcode.com/problems/search-suggestions-system/
class Solution {
public:
    struct Trie{
        Trie* child[26];
        bool isEnd=false;
    };
    void insertWord(Trie* root,string &word){
        Trie* curr=root;
        for(int i=0;i<word.size();i++){
            int ind=word[i]-'a';
            if(curr->child[ind]==NULL) curr->child[ind]=new Trie();
            curr=curr->child[ind];
        }
        curr->isEnd=true;
    }
    void helper(Trie* curr,vector<string>&v,string pref){
        if(v.size()==3) return;
        if(curr->isEnd) v.push_back(pref);
        for(int i=0;i<26;i++){
            if(curr->child[i]) helper(curr->child[i],v,pref+char(i+'a'));
        }
    }
    vector<string> search(Trie* root,string &pref){
        vector<string>v;
        Trie* curr=root;
        for(int i=0;i<pref.size();i++){
            int ind=pref[i]-'a';
            if(curr->child[ind]==NULL) return {};
            curr=curr->child[ind];
        }
        helper(curr,v,pref);
        return v;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* root=new Trie();
        for(string &str:products) insertWord(root,str);
        string pref;
        vector<vector<string>>ans;
        for(char &x:searchWord){
            pref+=x;
            ans.push_back(search(root,pref));
        }
        return ans;
    }
};