class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void helper(vector<int> adj[],vector<int>&vis,vector<int>&ans,int curr){
        vis[curr]=1;
        ans.push_back(curr);
        for(int x: adj[curr]){
            if(!vis[x]) helper(adj,vis,ans,x);
        }
    }
    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
        // Code here
        vector<int>vis(n,0);
        vector<int>ans;
        helper(adj,vis,ans,0);
        return ans;
    }
};