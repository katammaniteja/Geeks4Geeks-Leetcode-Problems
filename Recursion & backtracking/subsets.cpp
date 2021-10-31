
// https://leetcode.com/problems/subsets/
// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        ans.push_back(v);
        for(int i=0;i<nums.size();i++){
            int n=ans.size();
            for(int j=0;j<n;j++){
                vector<int>v=ans[j];
                v.push_back(nums[i]);
                ans.push_back(v);
            }
        }
        return ans;
    }
};