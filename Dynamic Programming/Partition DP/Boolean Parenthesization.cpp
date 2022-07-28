// https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1
class Solution{
public:
    int helper(vector<vector<vector<int>>>&dp,string &str,int i,int j,int curr){
        if(dp[i][j][curr]!=-1) return dp[i][j][curr];
        if(i==j){
            if(curr) return str[i]=='T';
            else return str[i]=='F';
        }
        int ans=0;
        for(int k=i+1;k<=j;k+=2){
            int lt=helper(dp,str,i,k-1,1);
            int lf=helper(dp,str,i,k-1,0);
            int rt=helper(dp,str,k+1,j,1);
            int rf=helper(dp,str,k+1,j,0);
            if(str[k]=='&'){
                if(curr) ans+= lt*rt;
                else ans+=lf*rf+rt*lf+lt*rf;
            }
            else if(str[k]=='|'){
                if(curr) ans+=lt*rt+rt*lf+lt*rf;
                else ans+=lf*rf;
            }
            else{
                if(curr) ans+= rt*lf+lt*rf;
                else ans+=lf*rf+lt*rt;
            }
        }
        return dp[i][j][curr]=(ans%1003);
    }
    int countWays(int n, string str){
        // code here
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return helper(dp,str,0,n-1,1);
    }
};