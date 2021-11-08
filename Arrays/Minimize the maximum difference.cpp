// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1
// Given an array arr[] denoting heights of N towers 
// and a positive integer K, you have to modify the 
// height of each tower either by increasing or decreasing 
// them by K only once. After modifying, height should 
// be a non-negative integer. Find out what could be 
// the possible minimum difference of the height of shortest 
// and longest towers after you have modified each tower.

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int smallest=arr[0]+k,largest=arr[n-1]-k;
        int ans=arr[n-1]-arr[0];
        int mi,ma;
        for(int i=0;i<n-1;i++){
            mi=min(smallest,arr[i+1]-k);
            ma=max(largest,arr[i]+k);
            if(mi<0) continue;
            ans=min(ans,ma-mi);
        }
        return ans;
    }
};