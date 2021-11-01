// https://leetcode.com/problems/majority-element/
// The majority element is the element that appears more than ⌊n / 2⌋ times. 
// You may assume that the majority element always exists in the array.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res=0,count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[res]) count++;
            else count--;
            if(count==0){
                count=1;
                res=i;
            }
        }
        return nums[res];
    }
};