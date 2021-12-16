// https://practice.geeksforgeeks.org/problems/count-the-number-of-subarrays/1
// Given an array A[] of N integers and a range(L, R). 
// The task is to find the number of subarrays having 
// sum in the range L to R (inclusive).

class Solution {
  public:
    long long count(vector<int>&nums,long long  r){
        long long count=0;
        long long sum=0;
        int i=0,j=0;
        while(j<nums.size()){
            sum+=nums[j];
            while( sum>r){
                sum-=nums[i];
                i++;
            }
            count+=j-i+1;
            j++;
        }
        return count;
    }
    long long countSubarray(int N,vector<int> nums,long long l,long long r) {
        return count(nums,r)-count(nums,l-1);
    }
};