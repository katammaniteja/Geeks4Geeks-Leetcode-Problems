// https://leetcode.com/problems/container-with-most-water/

// Given n non-negative integers a1, a2, ..., an , where each represents
// a point at coordinate (i, ai). n vertical lines are drawn such that 
// the two endpoints of the line i is at (i, ai) and (i, 0). Find two 
// lines, which, together with the x-axis forms a container, such that 
// the container contains the most water.

class Solution {
public:
    int maxArea(vector<int>& arr) {
        int i=0,j=arr.size()-1;
        int res=0;
        while(i<=j){
            res=max(res,min(arr[i],arr[j])*(j-i));
            if(arr[i]>arr[j]) j--;
            else i++;
        }
        return res;
    }
};