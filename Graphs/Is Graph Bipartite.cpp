// https://leetcode.com/problems/is-graph-bipartite/
class Solution {
public:
    bool helper(int src,vector<vector<int>>& graph,vector<int>&col){
        queue<pair<int,int>>q;
        q.push({src,0});
        col[src]=0;
        while(q.size()){
            int count=q.size();
            while(count--){
                auto tp=q.front();
                q.pop();
                int x=tp.first,y=tp.second;
                for(int val:graph[x]){
                    if(col[val]==-1){
                        col[val]=1-y;
                        q.push({val,1-y});
                    }
                    else if(y==col[val]) return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(!helper(i,graph,col)) return false;
            }
        }
        return true;
    }
};