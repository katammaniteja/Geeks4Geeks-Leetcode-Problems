// https://leetcode.com/problems/maximum-subarray/

// Given an integer array nums, find the contiguous subarray 
// (containing at least one number) which has the largest sum 
// and return its sum.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0],curr_sum=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            curr_sum=max(curr_sum+nums[i],nums[i]);
            res=max(res,curr_sum);
        }
        return res;
    }
};