// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

// There is a frog on the 1st step of an N stairs long staircase. 
// The frog wants to reach the Nth stair. HEIGHT[i] is the height 
// of the (i+1)th stair.If Frog jumps from ith to jth stair, the 
// energy lost in the jump is given by |HEIGHT[i-1] - HEIGHT[j-1] |.
// In the Frog is on ith staircase, he can jump either to (i+1)th 
// stair or to (i+2)th stair. Your task is to find the minimum 
// total energy used by the frog to reach from 1st stair to Nth stair.
int frogJump(int n, vector<int> &a)
{
    int dp[n];
    dp[0]=0;
    dp[1]=abs(a[1]-a[0]);
    for(int i=2;i<n;i++){
        dp[i]=min(abs(a[i]-a[i-2])+dp[i-2],abs(a[i]-a[i-1])+dp[i-1]);
    }
    return dp[n-1];
}