// https://leetcode.com/problems/maximal-rectangle/
// Given a rows x cols binary matrix filled with 0's and 1's, find the 
// largest rectangle containing only 1's and return its area.

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        stack<int>s;
        int res=0,curr;
        for(int i=0;i<n;i++){
            while(s.size() && arr[s.top()]>=arr[i]){
                int tp=s.top();
                s.pop();
                curr=arr[tp]*(s.size()?(i-s.top()-1):i);
                res=max(res,curr);
            }
            s.push(i);
        }
        while(s.size()){
            int tp=s.top();
            s.pop();
            curr=arr[tp]*(s.size()?(n-s.top()-1):n);
            res=max(res,curr);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size();
        vector<vector<int>>v;
        for(int i=0;i<m;i++){
            vector<int>a(n,0);
            v.push_back(a);
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1')  v[i][j]=1;
            }
        }
        int res=largestRectangleArea(v[0]);
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==0) continue;
                v[i][j]+=v[i-1][j];
            }
            res=max(res,largestRectangleArea(v[i]));
        }
        return res;
    }
};