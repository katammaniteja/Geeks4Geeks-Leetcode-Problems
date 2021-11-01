// https://leetcode.com/problems/find-all-duplicates-in-an-array/
// Given an integer array nums of length n where all the integers
// of nums are in the range [1, n] and each integer appears once
// or twice, return an array of all the integers that appears twice.

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>v;
        int i=0,n=nums.size();
        while(i<n){
            if(nums[i]==i+1) i++;
            else{
                if(nums[i]==nums[nums[i]-1]) i++;
                else swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(i=0;i<n;i++){
            if(nums[i]!=i+1) v.push_back(nums[i]);
        }
        return v;
    }
};