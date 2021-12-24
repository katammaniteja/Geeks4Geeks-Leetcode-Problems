// https://leetcode.com/problems/majority-element-ii/
// Given an integer array of size n, find all 
// elements that appear more than ⌊ n/3 ⌋ times.

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size()==1) return nums;
        vector<int>v;
        int c1=0,c2=0,num1=INT_MAX,num2=INT_MAX,n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==num1) c1++;
            else if(nums[i]==num2) c2++;
            else if(c1==0){
                c1=1;
                num1=nums[i];
            }
            else if(c2==0){
                c2=1;
                num2=nums[i];
            }
            else{
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
        for(int i=0;i<nums.size();i++){
            c1+=(nums[i]==num1);
            c2+=(nums[i]==num2);
        }
        if(c1>n/3) v.push_back(num1);
        if(c2>n/3)v.push_back(num2);
        return v;
    }
};