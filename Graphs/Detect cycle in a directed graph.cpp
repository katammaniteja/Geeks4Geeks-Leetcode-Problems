// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1#
bool dfs(vector<int> adj[],int i,vector<int>&visited,vector<int>&recSt){
    visited[i]=true;
    recSt[i]=true;
    for(int x: adj[i]){
        if(!visited[x]){
            if(dfs(adj,x,visited,recSt)) return true;
        }
        else if(recSt[x]) return true;
    }
    recSt[i]=false;
    return false;
}
bool isCyclic(int n, vector<int> adj[]) {
    // Code here
    vector<int>visited(n,0),recSt(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(dfs(adj,i,visited,recSt)) return true;
        }
    }
    return false;
}