// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<int> adj[],int i,vector<int>&visited,int parent){
        visited[i]=true;
        for(int x: adj[i]){
            if(!visited[x]){
                if(dfs(adj,x,visited,i)) return true;
            }
            else if(x!=parent) return true;
        }
        return false;
    }
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(dfs(adj,i,visited,-1)) return true;
            }
        }
        return false;
    }
};