// https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532
// You are given an array (0-based indexing) of positive integers and you have to 
// tell how many different ways of selecting the elements from the array are there 
// such that the sum of chosen elements is equal to the target number “tar”.
int findWays(vector<int> &nums, int tar)
{
    int n=nums.size();
    int dp[n+1][tar+1];
    for(int i=0;i<=n;i++) dp[i][0]=1;
    for(int i=1;i<=tar;i++) dp[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=tar;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=nums[i-1]) dp[i][j]+=dp[i-1][j-nums[i-1]];
        }
    }
    return dp[n][tar];
}