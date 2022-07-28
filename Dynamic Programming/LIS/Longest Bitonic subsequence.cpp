// https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1#
class Solution{
	public:
	void helper(vector<int>&arr,vector<int>&v){
	    int n=arr.size();
	    for(int i=0;i<n;i++){
	        v[i]=1;
	        for(int j=0;j<i;j++){
	            if(arr[j]<arr[i]) v[i]=max(v[i],1+v[j]);
	        }
	    }
	}
	int LongestBitonicSequence(vector<int>arr)
	{
	    // code here
	    int n=arr.size();
	    vector<int>lis(n),lds(n);
	    helper(arr,lis);
	    reverse(arr.begin(),arr.end());
	    helper(arr,lds);
	    reverse(lds.begin(),lds.end());
	    int res=0;
	    for(int i=0;i<n;i++) res=max(res,lis[i]+lds[i]-1);
	    return res;
	}
};

class Solution {
public:
    int helper(vector<int>&tail,int key){
        return lower_bound(tail.begin(),tail.end(),key)-tail.begin();
    }
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int>tail;
        tail.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(arr[i]>tail.back()) tail.push_back(arr[i]);
            else{
                tail[helper(tail,arr[i])]=arr[i];
            }
        }
        return tail.size();
    }
};