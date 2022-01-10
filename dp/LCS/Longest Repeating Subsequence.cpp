// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
// Given a string str, find the length of the longest repeating 
// subsequence such that it can be found twice in the given 
// string. The two identified subsequences A and B can use the 
// same ith character from string str if and only if that ith 
// character has different indices in A and B.
class Solution {
	public:
    int LongestRepeatingSubsequence(string s1){
        string s2=s1;
        int x=s1.length(),y=s2.length();
        int dp[x+1][y+1];
        for(int i=0;i<=x;i++) dp[i][0]=0;
        for(int i=0;i<=y;i++) dp[0][i]=0;
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1]==s2[j-1] && i!=j) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[x][y];
    }
};