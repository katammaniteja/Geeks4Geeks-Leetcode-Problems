// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003
int memo(vector<vector<int>> &points,vector<vector<int>> &dp,int i,int prev){
    int maxi=0;
    if(i==0){
        for(int j=0;j<=2;j++){
            if(j!=prev) maxi=max(maxi,points[0][j]);
        }
        return maxi;
    }
    if(dp[i][prev]!=-1) return dp[i][prev];
    for(int j=0;j<=2;j++){
        if(j!=prev){
            int profit=points[i][j]+func(points,dp,i-1,j);
            maxi=max(maxi,profit);
        }
    }
    dp[i][prev]=maxi;
    return maxi;
}
int ninjaTraining(int n, vector<vector<int>> &arr)
{
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(4));
    dp[0][0]=max(arr[0][1],arr[0][2]);
    dp[0][1]=max(arr[0][0],arr[0][2]);
    dp[0][2]=max(arr[0][0],arr[0][1]);
    dp[0][3]=max(arr[0][0],max(arr[0][1],arr[0][2]));
    for(int i=1;i<n;i++){
        for(int j=0;j<=3;j++){
            dp[i][j]=0;
            for(int k=0;k<3;k++){
                if(k!=j){
                    int point=arr[i][k]+dp[i-1][k];
                    dp[i][j]=max(point,dp[i][j]);
                }
            }
        }
    }
    return  dp[n-1][3];
}