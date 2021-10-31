// https://leetcode.com/problems/longest-valid-parentheses/
// Given a string containing just the characters '(' and ')', find the 
// length of the longest valid (well-formed) parentheses substring.

class Solution {
public:
    int longestValidParentheses(string str) {
        stack<int>s;
        int res=0,n=str.length();
        for(int i=0;i<n;i++){
            if(str[i]=='(') s.push(i);
            else{
                if(s.size()==0)  s.push(i);
                else if(str[s.top()]=='(') s.pop();
                else s.push(i);  
            }
        }
        int up=n;
        while(s.size()){
            int a=s.top();
            res=max(res,up-a-1);
            up=a;
            s.pop();
        }
        res=max(res,up);
        return res;
    }
};
