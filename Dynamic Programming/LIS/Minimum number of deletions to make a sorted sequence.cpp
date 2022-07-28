// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-to-make-a-sorted-sequence3248/1
class Solution{
	public:
	int helper(vector<int>&tail,int key){
        return lower_bound(tail.begin(),tail.end(),key)-tail.begin();
    }
	int minDeletions(int arr[], int n) 
	{ 
	    // Your code goes here
	    vector<int>tail;
        tail.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(arr[i]>tail.back()) tail.push_back(arr[i]);
            else{
                tail[helper(tail,arr[i])]=arr[i];
            }
        }
        return n-tail.size();
	} 
};