// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
class Solution{
public:
    int helper(vector<vector<int>>&dp,int arr[],int i,int j){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int curr=arr[i-1]*arr[k]*arr[j]+helper(dp,arr,i,k)+helper(dp,arr,k+1,j);
            ans=min(ans,curr);
        }
        return dp[i][j]=ans;
    }
    int matrixMultiplication(int n, int arr[])
    {
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int i=1,j=n-1;
        return helper(dp,arr,i,j);
    }
};