// https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
// Given a row wise sorted matrix of size RxC where R 
// and C are always odd, find the median of the matrix.
class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        int k=r*c/2;
        int mini=matrix[0][0],maxi=matrix[0][c-1];
        for(int i=0;i<r;i++) mini=min(matrix[i][0],mini);
        for(int i=0;i<r;i++) maxi=max(matrix[i][c-1],maxi);
        while(mini<maxi){
            int mid=mini+(maxi-mini)/2;
            int pos=0;
            for(int i=0;i<r;i++) 
                pos+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            if(pos<=k) mini=mid+1;
            else maxi=mid;
        }
        return mini;      
    }
};