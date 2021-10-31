// https://leetcode.com/problems/single-number-ii/
// Given an integer array nums where every element appears three times 
// except for one, which appears exactly once. Find the single element 
// and return it.

// You must implement a solution with a linear runtime complexity
//  and use only constant extra space.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        int64_t p=1;
        for(int i=1;i<=32;i++){
            int64_t sb=0;
            for(int &x:nums){
                sb+=(x&1);
                x=x>>1;
            }
            sb=sb%3;
            res+=sb*p;
            p=p*2;
        }
        return res;
    }
};