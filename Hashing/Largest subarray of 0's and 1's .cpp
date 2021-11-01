// https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1

// Given an array of 0s and 1s. Find the length of the largest subarray 
// with equal number of 0s and 1s.

class Solution{
  public:
    int maxLen(int arr[], int n)
    {
        for(int i=0;i<n;i++){
            if(!arr[i]) arr[i]=-1;
        }
        unordered_map<int,int>mp;
        int res=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0) res=max(res,i+1);
            if(mp.find(sum)==mp.end()) mp[sum]=i;
            else res=max(res,i-mp[sum]);
        }
        return res;
    }
};
