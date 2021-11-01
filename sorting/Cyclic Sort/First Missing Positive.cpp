// https://leetcode.com/problems/first-missing-positive/

// Given an unsorted integer array nums, return the smallest
//  missing positive integer.

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0,n=nums.size();
        while(i<nums.size()){
            if(nums[i]==i+1 || nums[i]>=n || nums[i]<=0) i++;
            else
                if(nums[i]==nums[nums[i]-1]) i++;
                else swap(nums[i],nums[nums[i]-1]);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};
