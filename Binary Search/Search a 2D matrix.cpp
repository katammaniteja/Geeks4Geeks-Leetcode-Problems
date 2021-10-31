// https://leetcode.com/problems/search-a-2d-matrix/
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int m=arr.size(),n=arr[0].size();
        int l=0,r=m-1,mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(arr[mid][0]==target) return true;
            if(arr[mid][0]>target) r=mid-1;
            if(arr[mid][0]<target){
                if(mid==m-1 || arr[mid+1][0]>target) break;
                else l=mid+1;
            }
        }
        l=0,r=n-1;
        while(l<=r){
            int mid1=l+(r-l)/2;
            if(arr[mid][mid1]==target) return true;
            if(arr[mid][mid1]>target) r=mid1-1;
            else l=mid1+1;
        }
        return false;
    }
};