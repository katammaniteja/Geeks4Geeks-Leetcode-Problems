// https://leetcode.com/problems/permutations/
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

class Solution {
public:
    void permutations(vector<vector<int>>&ans,vector<int>&v,vector<int>&nums,int i){
        if(i==nums.size()){
            ans.push_back(v);
            return;
        }
        int a=nums[i];
        for(int j=0;j<=v.size();j++){
            if(j!=0 && nums[j-1]==a) continue;
            v.insert(v.begin()+j,a);
            permutations(ans,v,nums,i+1);
            v.erase(v.begin()+j);
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        permutations(ans,v,nums,0);
        return ans;
    }
};