// https://practice.geeksforgeeks.org/problems/topological-sort/1#
vector<int> topoSort(int v, vector<int> adj[]) 
{
    // code here
    vector<int>indegree(v,0);
    for(int i=0;i<v;i++){
        for(int x:adj[i]) indegree[x]++;
    }
    queue<int>q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0) q.push(i);
    }
    vector<int>ans;
    while(q.size()){
        int tp=q.front();
        q.pop();
        ans.push_back(tp);
        for(int x:adj[tp]){
            indegree[x]--;
            if(indegree[x]==0) q.push(x);
        }
    }
    return ans;
}