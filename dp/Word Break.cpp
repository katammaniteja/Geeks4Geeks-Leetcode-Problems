// https://leetcode.com/problems/word-break/
class Solution {
public:
    bool helper(string str,int pos,vector<int>&memo,unordered_set<string>&s){
        if(pos==str.size()) return true;
        if(memo[pos]!=-1) return memo[pos];
        for(int i=pos;i<str.size();i++){
            string temp=str.substr(pos,i-pos+1);
            if(s.find(temp)!=s.end() && helper(str,i+1,memo,s)) return memo[pos]=true;
        }
        return memo[pos]=false;
    }
    bool wordBreak(string str, vector<string>& wordDict) {
        unordered_set<string>s;
        for(string &x:wordDict) s.insert(x);
        vector<int>memo(str.size(),-1);
        return helper(str,0,memo,s);
    }
};