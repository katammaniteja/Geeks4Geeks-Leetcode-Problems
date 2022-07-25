// https://leetcode.com/problems/132-pattern/
// Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] 
// such that i < j < k and nums[i] < nums[k] < nums[j]. Return true if there is a 132 pattern in nums, otherwise, return false.
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre_min(n,INT_MAX);
        for(int i=1;i<n;i++){
            pre_min[i]=min(nums[i-1],pre_min[i-1]);
        }
        stack<int>s;
        for(int i=n-1;i>=1;i--){
            while(s.size() && s.top()<=pre_min[i]) s.pop();
            if(s.size() && s.top()<nums[i]) return true;
            s.push(nums[i]);
        }
        return false;
    }
};