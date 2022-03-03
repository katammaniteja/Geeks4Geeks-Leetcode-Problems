class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int n, vector<int> adj[]) {
        // Code here
        int visited[n]={0};
        queue<int>q;
        q.push(0);
        visited[0]=1;
        vector<int>ans;
        while(q.size()){
            int tp=q.front();
            q.pop();
            ans.push_back(tp);
            for(int x: adj[tp]){
                if(!visited[x]){
                    visited[x]=1;
                    q.push(x);
                }
            }
        }
        return ans;
    }
};