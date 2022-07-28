// https://leetcode.com/problems/burst-balloons/
class Solution {
public:
    int helper(vector<vector<int>>&dp,vector<int>& nums,int i,int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MIN;
        for(int k=i;k<=j;k++){
            int curr=nums[i-1]*nums[k]*nums[j+1]+helper(dp,nums,i,k-1) + helper(dp,nums,k+1,j);
            ans=max(ans,curr);
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(dp,nums,1,n-2);
    }
};