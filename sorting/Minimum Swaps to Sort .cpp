// https://practice.geeksforgeeks.org/problems/minimum-swaps/1
// Given an array of n distinct elements. Find the minimum number of 
// swaps required to sort the array in strictly increasing order.

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int i,n=nums.size(),count=0;
	    unordered_map<int,int>mp;
	    vector<int>temp=nums;
	    sort(temp.begin(),temp.end());
	    for(i=0;i<n;i++){
	        mp[temp[i]]=i;
	    }
	    i=0;
	    while(i<n){
	        if(nums[i]==temp[i]) i++;
	        else{
	            swap(nums[i],nums[mp[nums[i]]]);
	            count++;
	        }
	    }
	    return count;
	}
};