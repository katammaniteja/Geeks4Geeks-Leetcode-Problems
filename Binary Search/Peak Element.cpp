// https://leetcode.com/problems/find-peak-element/
// A peak element is an element that is strictly greater than its neighbors.


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if((mid==0||nums[mid]>nums[mid-1] )&&(mid==nums.size()-1|| nums[mid]>nums[mid+1]))                      return mid;
            else{
                if(mid>0 && nums[mid-1]>nums[mid]) r=mid-1;
                else l=mid+1;
            }
        }
        return -1;
    }
};