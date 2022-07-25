// https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string str)
    {
        int n=str.length();
        stack<int>s;
        for(int i=0;i<n;i++){
            if(str[i]<=57 && str[i]>=48) s.push(str[i]-48);
            else{
                int a,b;
                b=s.top();
                s.pop();
                a=s.top();
                s.pop();
                if(str[i]=='+') s.push(a+b);
                else if(str[i]=='-') s.push(a-b);
                else if(str[i]=='*') s.push(a*b);
                else s.push(a/b);
            }
        }
        return s.top();
    }
};