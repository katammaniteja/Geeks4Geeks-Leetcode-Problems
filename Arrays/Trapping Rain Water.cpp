// https://leetcode.com/problems/trapping-rain-water/
// Given n non-negative integers representing an elevation map where the 
// width of each bar is 1, compute how much water it can trap after raining.

class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        int left[n],right[n];
        left[0]=arr[0];
        for(int i=1;i<n;i++) left[i]=max(arr[i],left[i-1]);
        right[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--) right[i]=max(arr[i],right[i+1]);
        int res=0;
        for(int i=0;i<n;i++) res+=min(left[i],right[i])-arr[i];
        return res;
    }
};