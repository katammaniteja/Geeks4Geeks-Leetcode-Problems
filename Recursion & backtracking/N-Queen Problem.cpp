// https://practice.geeksforgeeks.org/problems/n-queen-problem0315/0/
// The n-queens puzzle is the problem of placing n queens on a (n×n) 
// chessboard such that no two queens can attack each other.
// Given an integer n, find all distinct solutions to the n-queens puzzle. 
// Each solution contains distinct board configurations of the n-queens’ 
// placement, where the solutions are a permutation of [1,2,3..n] in 
// increasing order, here the number in the ith place denotes that the 
// ith-column queen is placed in the row with that number.

class Solution{
public:
    bool valid(vector<vector<int>>&matrix,int row,int col){
        // vertical check
        for(int i=0;i<row;i++){
            if(matrix[i][col]) return false;
        }
        
        //diagonal left
        for(int i=1;i<=min(row,col);i++){
            if(matrix[row-i][col-i]) return false;
        }
        
        //daigonal right
        for(int i=1;i<=min(row,int(matrix[0].size()-col-1));i++){
            if(matrix[row-i][col+i]) return false;
        }
        return true;
    }
    void backtrack(vector<vector<int>>&ans,vector<int>&v,vector<vector<int>>&matrix,int row){
        if(row==matrix.size()){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<matrix.size();i++){
            
            if(valid(matrix,row,i)) {
                v.push_back(i+1);
                matrix[row][i]=1;
                backtrack(ans,v,matrix,row+1);
                v.pop_back();
                matrix[row][i]=0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>>matrix;
        vector<vector<int>>ans;
        vector<int>v;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) v.push_back(0);
            matrix.push_back(v);
            v.clear();
        }
        backtrack(ans,v,matrix,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};