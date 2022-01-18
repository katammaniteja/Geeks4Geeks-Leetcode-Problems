// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1#
// Given K sorted arrays arranged in the form of a matrix of size K*K. 
// The task is to merge them into one sorted array.
class Solution
{
    public:
    //Function to merge k sorted arrays.
    struct comp{
        bool operator()(vector<int>&a,vector<int>&b){
            return a[0]>b[0];
        }
    };
    vector<int> mergeKArrays(vector<vector<int>> &arr, int k)
    {
        //code here
        vector<int>v;
        priority_queue<vector<int>,vector<vector<int>>,comp>pq;
        for(int i=0;i<k;i++) pq.push({arr[i][0],i,0});
        while(pq.size()){
            auto tp=pq.top();
            pq.pop();
            v.push_back(tp[0]);
            int r=tp[1];
            int c=tp[2];
            if(c+1<k) pq.push({arr[r][c+1],r,c+1});
        }
        return v;
    }
};