// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). 
// Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can
// move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and 
// rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.

class Solution{
    public:
    void track(vector<string>&v,vector<vector<int>>&m,int n,string p,int i,int j){
        
        if(!m[i][j]) return;
        
        if(i==n && j==n){
            v.push_back(p);
            return;
        }
        
        m[i][j]=0;
        
        if(i>0){
            track(v,m,n,p+'U',i-1,j);
        }
        if(j>0){
            track(v,m,n,p+'L',i,j-1);
        }
        if(i<n){
            track(v,m,n,p+'D',i+1,j);
        }
        if(j<n){
            track(v,m,n,p+'R',i,j+1);
        }
        
        m[i][j]=1;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        track(ans,m,n-1,"",0,0);
       sort(ans.begin(),ans.end());
        return ans;
    }
};