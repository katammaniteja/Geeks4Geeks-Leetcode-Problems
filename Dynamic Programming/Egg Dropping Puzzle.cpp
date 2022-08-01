// https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int helper(vector<vector<int>>&dp,int n,int k){
        if(dp[n][k]!=-1) return dp[n][k];
        if(k==0 || k==1 || n==1) return dp[n][k]=k;
        int ans=INT_MAX;
        for(int i=1;i<=k;i++){
            int res=max(helper(dp,n,k-i),helper(dp,n-1,i-1));
            ans=min(ans,res);
        }
        return dp[n][k]=ans+1;
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return helper(dp,n,k);
    }
};