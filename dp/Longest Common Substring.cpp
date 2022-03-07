// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
// Given two strings. The task is to find the length of the longest common substring.
class Solution{
    public:
    int longestCommonSubstr (string s1, string s2)
    {
        // your code here
        int ans=0;
        int n1=s1.length(),n2=s2.length();
        int dp[n1+1][n2+1];
        for(int i=0;i<=n1;i++) dp[i][0]=0;
        for(int i=0;i<=n2;i++) dp[0][i]=0;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=0;
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};