// https://practice.geeksforgeeks.org/problems/count-of-subarrays5922/1

// Given an array of N positive integers  Arr1, Arr2 ............ Arrn. 
// The value of each contiguous subarray of given array is the maximum 
// element present in that subarray. The task is to return the number 
// of subarrays having value strictly greater than K

class Solution{
public:
	// #define ll long long

	ll countSubarray(int arr[], int n, int k) {
	    int i=0;
	    ll res=0;
	    while(i<n){
	        if(arr[i]>k){ i++;
	        continue;
	        }
	        int count=0;
	        while(i<n && arr[i]<=k){
	            count++;
	            i++;
	        }
	        res+=count*(count+1)/2;
	    }
	    
	    return (ll)n*(n+1)/2 -res;
	}
};
