// https://leetcode.com/problems/continuous-subarray-sum/
// Given an integer array nums and an integer k, return true if 
// nums has a continuous subarray of size at least two whose elements 
// sum up to a multiple of k, or false otherwise.

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int count=0,sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]%k==0) count--;
            sum=sum+nums[i];
            if(sum%k==0) count++;
            if(mp.find(sum%k)!=mp.end()) count+=mp[sum%k];
            mp[sum%k]++;
        }
        return count>=1;
    }
};