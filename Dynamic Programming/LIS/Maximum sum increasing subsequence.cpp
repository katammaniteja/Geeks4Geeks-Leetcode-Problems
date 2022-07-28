// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1#
class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int>mlis(n);
	    for(int i=0;i<n;i++){
	        mlis[i]=arr[i];
	        for(int j=0;j<i;j++){
	            if(arr[j]<arr[i]) mlis[i]=max(mlis[i],mlis[j]+arr[i]);
	        }
	    }
	    int res=arr[0];
	    for(int i=0;i<n;i++) res=max(res,mlis[i]);
	    return res;
	}  
};