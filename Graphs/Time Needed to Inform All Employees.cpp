// https://leetcode.com/problems/time-needed-to-inform-all-employees/
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            if(i==headID) continue;
            adj[manager[i]].push_back(i);
        }
        queue<pair<int,int>>q;
        q.push({headID,0});
        int ans=0;
        while(q.size()){
            int curr=0,count=q.size();
            while(count--){
                auto top=q.front();
                q.pop();
                int dur=top.second+informTime[top.first];
                ans=max(ans,dur);
                for(int x:adj[top.first]) q.push({x,dur});
            }
        }
        return ans;
    }
};