// https://leetcode.com/problems/design-add-and-search-words-data-structure/
class WordDictionary {
public:
    struct Trie{
        Trie* child[26];
        bool isEnd=false;
    };
    Trie* root;
    WordDictionary() {
        root=new Trie();
    }
    void addWord(string word) {
        Trie* curr=root;
        for(int i=0;i<word.size();i++){
            int ind=word[i]-'a';
            if(curr->child[ind]==NULL) curr->child[ind]=new Trie();
            curr=curr->child[ind];
        }
        curr->isEnd=true;
    }
    bool helper(Trie* curr,string &word,int ind){
        if(ind==word.size()) return curr->isEnd;
        if(word[ind]=='.'){
            for(int i=0;i<26;i++){
                if(curr->child[i] && helper(curr->child[i],word,ind+1)) return true;
            }
        }
           else{
               int i=word[ind]-'a';
               if(curr->child[i] && helper(curr->child[i],word,ind+1)) return true;
           }
           return false;
    }
    bool search(string word) {
        Trie* curr=root;
        return helper(curr,word,0);
    }
};
