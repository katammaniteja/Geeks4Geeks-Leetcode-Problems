// https://leetcode.com/problems/unique-binary-search-trees/
// Given an integer n, return the number of structurally unique BST's 
// (binary search trees) which has exactly n nodes of unique values from 1 to n.
class Solution {
public:
    int helper(vector<int>&dp,int n){
        if(n <= 1) return 1;
        if(dp[n]) return dp[n];
        for(int i = 1; i <= n; i++) 
            dp[n] += helper(dp,i-1) * helper(dp,n-i);
        return dp[n];
    }
    int numTrees(int n) {
       vector<int>dp(n+1,0);
        dp[0]=1,dp[0]=1;
        return helper(dp,n);
    }
};