// You are given an integer array coins representing coins of 
// different denominations and an integer amount representing 
// a total amount of money. Return the number of combinations 
// that make up that amount. If that amount of money cannot be 
// made up by any combination of the coins, return 0.
// You may assume that you have an infinite number of each kind of coin.
class Solution {
public:
    int change(int sum, vector<int>& arr) {
        int n=arr.size();
        int dp[n+1][sum+1];
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=1;i<=sum;i++) dp[0][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1]>j) dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j]+dp[i][j-arr[i-1]];
            }
        }
        return dp[n][sum];
    }
};