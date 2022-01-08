// Given a rod of length N inches and an array of prices, 
// price[] that contains prices of all pieces of size smaller 
// than N. Determine the maximum value obtainable by cutting 
// up the rod and selling the pieces.
class Solution{
  public:
    int cutRod(int price[], int n) {
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i>j) dp[i][j]=dp[i-1][j];
                else dp[i][j]=max(dp[i-1][j],price[i-1]+dp[i][j-i]);
            }
        }
        return dp[n][n];
    }
};