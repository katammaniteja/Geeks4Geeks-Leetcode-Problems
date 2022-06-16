// https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1#
class Solution {
  public:
    int bfs(vector<vector<int>>matrix,int x,int y){
        int ans=0;
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        visited[0][0]=1;
        queue<pair<int,int>>q;
        q.push({0,0});
        while(q.size()){
            int count=q.size();
            while(count--){
                auto tp=q.front();
                q.pop();
                int i=tp.first,j=tp.second;
                if(i==x && j==y) return ans;
                if(i+1<m && !visited[i+1][j] && matrix[i+1][j]){
                    visited[i+1][j]=1;
                    q.push({i+1,j});
                }
                if(i-1>=0 && !visited[i-1][j] && matrix[i-1][j]){
                    visited[i-1][j]=1;
                    q.push({i-1,j});
                }
                if(j+1<n && !visited[i][j+1] && matrix[i][j+1]){
                    visited[i][j+1]=1;
                    q.push({i,j+1});
                }
                if(j-1>=0 && !visited[i][j-1] && matrix[i][j-1]){
                    visited[i][j-1]=1;
                    q.push({i,j-1});
                }
            }
            ans++;
        }
        return -1;
    }
    int shortestDistance(int m, int n, vector<vector<int>> matrix, int x, int y) {
        // code here
        if(matrix[0][0]==0) return -1;
        return bfs(matrix,x,y);
    }
};