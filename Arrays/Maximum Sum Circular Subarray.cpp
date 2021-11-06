// https://leetcode.com/problems/maximum-sum-circular-subarray/
// Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
class Solution {
public:
    int kadanes(vector<int>&nums){
        int curr_max=nums[0],res=nums[0];
        for(int i=1;i<nums.size();i++){
            curr_max=max(curr_max+nums[i],nums[i]);
            res=max(res,curr_max);
        }
        return res;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int lcs=kadanes(nums);
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            nums[i]=-nums[i];
        }
        if(lcs<0) return lcs;
        return max(lcs,sum+kadanes(nums));
    }
};
