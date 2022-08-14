// https://leetcode.com/problems/combination-sum-iv/
class Solution {
public:
    int helper(vector<int>& nums, int target, vector<int>&dp){
        if(target<0) return 0;
        if(dp[target]!=-1) return dp[target];
        if(target==0) return dp[target]=1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=helper(nums,target-nums[i],dp);
        }
        return dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return helper(nums,target,dp);
    }
};