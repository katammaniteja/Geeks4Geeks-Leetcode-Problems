// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/
// Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 
class Solution{   
public:
    bool isSubsetSum(int n, int arr[], int sum){
        bool dp[n+1][sum+1];
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=1;i<=sum;i++) dp[0][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1]>j) dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
        return dp[n][sum];
    }
};