// https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1#

class Solution{
    public:
    //Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string str){
        unordered_map<char,int>mp;
        mp['(']=0,mp['-']=1,mp['+']=1,mp['/']=2,mp['*']=2,mp['^']=3;
        stack<char>s;
        string ans="";
        int n=str.length();
        for(int i=0;i<n;i++){
            if((str[i]<='z' && str[i]>='a')||(str[i]<='Z' && str[i]>='A')) ans+=str[i];
            else{
                if(str[i]=='(' || str[i]=='^' || !s.size()) s.push(str[i]);
                else if(str[i]==')'){
                    while(s.top()!='('){
                        ans+=s.top();
                        s.pop();
                    }
                    s.pop();
                }
                else{
                    if(mp[s.top()]<mp[str[i]]) s.push(str[i]);
                    else{
                        while(s.size() && mp[s.top()]>=mp[str[i]]){
                            ans+=s.top();
                            s.pop();
                        }
                        s.push(str[i]);
                    }
                }
            }
        }
        while(s.size()){
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};