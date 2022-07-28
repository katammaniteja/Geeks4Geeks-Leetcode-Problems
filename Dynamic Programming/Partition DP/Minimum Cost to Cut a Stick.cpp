// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
class Solution {
public:
    int helper(vector<vector<int>>&dp,vector<int>&cuts,int i,int j){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i>j) return 0;
        int ans=INT_MAX;
        for(int k=i;k<=j;k++){
            int curr=cuts[j+1]-cuts[i-1]+helper(dp,cuts,i,k-1)+ helper(dp,cuts,k+1,j);
            ans=min(ans,curr);
        }
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return helper(dp,cuts,1,cuts.size()-2);
    }
};