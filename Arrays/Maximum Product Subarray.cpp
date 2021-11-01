// https://leetcode.com/problems/maximum-product-subarray/
// Given an integer array nums, find a contiguous non-empty 
// subarray within the array that has the largest product, 
// and return the product.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res1=1,res2=1,res=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                swap(res1,res2);
            }
            res1=max(res1*nums[i],nums[i]);
            res2=min(res2*nums[i],nums[i]);
            res=max(res,res1);
        }
        return res;
    }
};