// https://leetcode.com/problems/combination-sum/
// Given an array of distinct integers candidates and a target integer target,
//  return a list of all unique combinations of candidates where the chosen numbers sum to target. 
//  You may return the combinations in any order.

class Solution {
public:
    void combinations(vector<vector<int>>&ans,vector<int>&v,vector<int>&nums,int target,int i){
        if(i==nums.size()){
            if(target==0) ans.push_back(v);
            return;
        }
        if(target-nums[i]>=0){
            v.push_back(nums[i]);
            combinations(ans,v,nums,target-nums[i],i);
            v.pop_back();
        }
        combinations(ans,v,nums,target,i+1);
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        combinations(ans,v,nums,target,0);
        return ans;
    }
};