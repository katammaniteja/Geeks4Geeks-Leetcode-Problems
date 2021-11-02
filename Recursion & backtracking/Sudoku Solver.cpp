// https://leetcode.com/problems/sudoku-solver/
// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

//     Each of the digits 1-9 must occur exactly once in each row.
//     Each of the digits 1-9 must occur exactly once in each column.
//     Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

// The '.' character indicates empty cells.

class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int row,int col,int n){
        //chech row and col
        for(int i=0;i<9;i++){
            if(board[i][col]==n) return false;
            if(board[row][i]==n) return false;
        }
        
        //check box
        int rowStart=row-row%3,colStart=col-col%3;
        for(int i=rowStart;i<=rowStart+2;i++){
            for(int j=colStart;j<=colStart+2;j++){
                if(board[i][j]==n) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int row,col;
        bool empty=true;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    row=i;
                    col=j;
                    empty=false;
                    break;
                }
            }
            if(!empty) break;
        }
        if(empty) return true;
        for(int i=49;i<=57;i++){
            if(isSafe(board,row,col,i)){
                board[row][col]=i;
                if(solve(board)) return true;
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};