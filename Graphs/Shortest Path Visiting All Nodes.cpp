// https://leetcode.com/problems/shortest-path-visiting-all-nodes/
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        int all=(1<<n)-1;
        set<pair<int,int>>visited;
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++){
            q.push({i,{0,1<<i}});
            visited.insert({i,1<<i});
        }
        while(q.size()){
            auto tp=q.front();
            q.pop();
            int val=tp.first,dist=tp.second.first,mask=tp.second.second;
            for(int x:graph[val]){
                int new_mask=(mask|(1<<x));
                if(new_mask==all) return dist+1;
                if(visited.find({x,new_mask})==visited.end()) {
                    q.push({x,{dist+1,new_mask}});
                    visited.insert({x,new_mask});
                }
            }
        }
        return 0;
    }
};