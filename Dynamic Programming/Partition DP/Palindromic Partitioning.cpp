// https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
class Solution{
public:
    bool check(string &str,int i,int j){
        while(i<=j){
            if(str[i]!=str[j]) return false;
            i++,j--;
        }
        return true;
    }
    int helper(vector<vector<int>>&dp,string &str,int i,int j){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==j) return 0;
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            if(check(str,i,k)){
                int curr=1+helper(dp,str,k+1,j);
                ans=min(ans,curr);
            }
        }
        return dp[i][j]=ans;
        
    }
    int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(dp,str,0,n)-1;
    }
};