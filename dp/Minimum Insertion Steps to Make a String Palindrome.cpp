// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// Given a string s. In one step you can insert any character at any index of the string.
// Return the minimum number of steps to make s palindrome.
// A Palindrome String is one that reads the same backward as well as forward.

 class Solution {
public:
    int minInsertions(string str1) {
        int n=str1.length();
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
            dp[0][i]=0;
        }
        string str2=str1;
        reverse(str2.begin(),str2.end());
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return n-dp[n][n];
    }
};