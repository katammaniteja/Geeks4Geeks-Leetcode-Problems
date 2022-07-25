// https://leetcode.com/problems/largest-rectangle-in-histogram/
// Given an array of integers heights representing the histogram's bar height where the width
// of each bar is 1, return the area of the largest rectangle in the histogram.

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
};