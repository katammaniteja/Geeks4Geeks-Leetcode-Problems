// Given two strings str1 and str2, return the shortest string that 
// has both str1 and str2 as subsequences. If there are multiple 
// valid strings, return any of them. A string s is a subsequence of 
// string t if deleting some number of characters from t (possibly 0) 
// results in the string s.
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1=str1.length(),n2=str2.length();
        int dp[n1+1][n2+1];
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                if(i==0 || j==0) dp[i][j]=0;
                else if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        string lcs;
        int i=n1,j=n2;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                lcs.push_back(str1[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j]>=dp[i][j-1]) i--;
            else j--;
        }
        reverse(lcs.begin(),lcs.end());
        string ans;
        i=0,j=0;int k=0;
        while(i<str1.length() && j<str2.length() && k<lcs.length()){
            if(str1[i]==lcs[k]){
                while(j<str2.length() && str2[j]!=lcs[k]){
                    ans.push_back(str2[j]);
                    j++;
                }
                ans.push_back(str1[i]);
                i++,j++,k++;
            }
            else{
                ans.push_back(str1[i]);
                i++;
            }
        }
        while(i<str1.length()){
            ans.push_back(str1[i]);
            i++;
        }
        while(j<str2.length()){
            ans.push_back(str2[j]);
            j++;
        }
        return ans;
    }
};