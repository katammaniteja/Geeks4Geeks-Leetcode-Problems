// https://leetcode.com/problems/next-permutation/

// Implement next permutation, which rearranges numbers into the 
// lexicographically next greater permutation of numbers.

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),i;
        for(i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]) break;
        }
        if(i<0){
            sort(nums.begin(),nums.end());
            return;
        }
        for(int j=n-1;j>=0;j--){
            if(nums[j]>nums[i]){
                swap(nums[j],nums[i]);
                sort(nums.begin()+i+1,nums.end());
                return;
            }
        }
    }
};