// Given an integer array arr of size N, the task 
// is to divide it into two sets S1 and S2 such 
// that the absolute difference between their sums 
// is minimum and find the minimum difference
class Solution{
  public:
	int minDifference(int arr[], int n)  { 
	    int sum=0;
	    for(int i=0;i<n;i++) sum+=arr[i];
	    bool dp[n+1][sum+1];
	    for(int i=0;i<=n;i++) dp[i][0]=1;
	    for(int i=1;i<=sum;i++) dp[0][i]=0;
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=sum;j++){
	            if(arr[i-1]>j) dp[i][j]=dp[i-1][j];
	            else dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
	        }
	    }
	    int ans=INT_MAX;
	    for(int i=0;i<=sum;i++){
	        if(dp[n][i]) ans=min(ans,abs(sum-2*i));
	    }
	    return ans;
	} 
};