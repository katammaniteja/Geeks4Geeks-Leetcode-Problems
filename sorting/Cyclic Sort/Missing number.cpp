// https://leetcode.com/problems/missing-number/
// Given an array nums containing n distinct numbers in the range [0, n],
//  return the only number in the range that is missing from the array.

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0,n=nums.size();
        while(i<nums.size()){
            if(nums[i]==i || nums[i]==n) i++;
            else swap(nums[i],nums[nums[i]]);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i) return i;
        }
        return n;
    }
};