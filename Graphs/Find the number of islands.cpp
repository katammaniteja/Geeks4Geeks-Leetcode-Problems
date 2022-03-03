// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
class Solution {
  public:
    // Function to find the number of islands.
    bool isSafe(int i,int j,vector<vector<char>>& arr){
        if(i<0 || j<0 || i==arr.size() || j==arr[0].size() || arr[i][j]=='0') return false;
        return true;
    }
    void bfs(vector<vector<char>>& arr,vector<vector<int>>& visited,int x,int y){
        visited[x][y]=1;
        queue<pair<int,int>>q;
        q.push({x,y});
        while(q.size()){
            auto curr=q.front();
            q.pop();
            int i=curr.first,j=curr.second;
            if(isSafe(i+1,j,arr) && !visited[i+1][j]){
                q.push({i+1,j});
                visited[i+1][j]=1;
            }
            if(isSafe(i+1,j+1,arr) && !visited[i+1][j+1]){
                q.push({i+1,j+1});
                visited[i+1][j+1]=1;
            }
            if(isSafe(i+1,j-1,arr) && !visited[i+1][j-1]){
                q.push({i+1,j-1});
                visited[i+1][j-1]=1;
            }
            if(isSafe(i-1,j,arr) && !visited[i-1][j]){
                q.push({i-1,j});
                visited[i-1][j]=1;
            }
            if(isSafe(i-1,j-1,arr) && !visited[i-1][j-1]){
                q.push({i-1,j-1});
                visited[i-1][j-1]=1;
            }
            if(isSafe(i-1,j+1,arr) && !visited[i-1][j+1]){
                q.push({i-1,j+1});
                visited[i-1][j+1]=1;
            }
            if(isSafe(i,j+1,arr) && !visited[i][j+1]){
                q.push({i,j+1});
                visited[i][j+1]=1;
            }
            if(isSafe(i,j-1,arr) && !visited[i][j-1]){
                q.push({i,j-1});
                visited[i][j-1]=1;
            }
        }
    }
    int numIslands(vector<vector<char>>& arr) {
        // Code here
        int m=arr.size(),n=arr[0].size();
        int count=0;
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && arr[i][j]=='1'){
                    count++;
                    bfs(arr,visited,i,j);
                }
            }
        }
        return count;
    }
};