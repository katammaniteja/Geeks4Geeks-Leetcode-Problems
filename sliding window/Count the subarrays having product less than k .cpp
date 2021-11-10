// https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1

// Given an array of positive numbers, the task is to find the 
// number of possible contiguous subarrays having product less 
// than a given number k.

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& arr, int n, long long k) {
        int64_t p=1;
        int start=0;
        int count=0;
        for(int i=0;i<n;i++){
            p=p*arr[i];
            while(start<i && p>=k) p=p/arr[start++];
            if(p<k) count+=i-start+1;
        }
        return count;
    }
};