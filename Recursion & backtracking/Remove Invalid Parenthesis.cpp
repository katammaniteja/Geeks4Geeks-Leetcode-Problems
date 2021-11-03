
// https://leetcode.com/problems/remove-invalid-parentheses/
// Given a string s that contains parentheses and letters, remove the 
// minimum number of invalid parentheses to make the input string valid.


class Solution {
public:
    unordered_set<string>set;
    int isValid(string str){
        stack<char>s;
        for(int i=0;i<str.length();i++){
            if(str[i]>='a' && str[i]<='z') continue;
            if(str[i]=='(') s.push(str[i]);
            else{
                if(s.size() && s.top()=='(') s.pop();
                else s.push(str[i]);
            }
        }
        return s.size();
    }
    void remove(vector<string>&ans,string str,int n,int start){
        if(set.find(str)!=set.end()) return;
        set.insert(str);
        if(n==0){
            if(!isValid(str)) ans.push_back(str);
            return;
        }
        for(int i=start;i<str.length();i++){
            if(str[i]>='a' && str[i]<='z') continue;
            string s=str.substr(0,i)+str.substr(i+1);
             remove(ans,s,n-1,i);
        }
        
    }
    vector<string> removeInvalidParentheses(string str) {
        vector<string>ans;
        remove(ans,str,isValid(str),0);
        return ans;
    }
};