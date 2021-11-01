// https://leetcode.com/problems/subarray-sum-equals-k/
// Given an array of integers nums and an integer k, return the 
// total number of continuous subarrays whose sum equals to k.

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                if(nums[i]==k) count++;
                mp[nums[i]]++;
                continue;
            }
            nums[i]+=nums[i-1];
            if(nums[i]==k) count++;
            if(mp.find(nums[i]-k)!=mp.end()) count+=mp[nums[i]-k];
            mp[nums[i]]++;
        }
        return count;
    }
};