// https://leetcode.com/problems/sort-colors/

// Given an array nums with n objects colored red, white, or blue, sort 
// them in-place so that objects of the same color are adjacent, with the 
// colors in the order red, white, and blue. We will use the integers 
// 0, 1, and 2 to represent the color red, white, and blue, respectively.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,m=0,r=nums.size()-1;
        while(m<=r){
            if(nums[m]==0) swap(nums[l++],nums[m++]);
            else if(nums[m]==2) swap(nums[m],nums[r--]);
            else m++;
        }
    }
};
