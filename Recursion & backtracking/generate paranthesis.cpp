// https://leetcode.com/problems/generate-parentheses/
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]


class Solution {
public:
    void func(vector<string>&ans,string &str,int open,int close){
        if(open==0 && close==0){
            ans.push_back(str);
            return;
        }
        if(open) {
            str.push_back('(');
            func(ans,str,open-1,close);
            str.pop_back();
        }
        if(close>open) {
            str.push_back(')');
            func(ans,str,open,close-1);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string str="";
        func(ans,str,n,n);
        return ans;
    }
};