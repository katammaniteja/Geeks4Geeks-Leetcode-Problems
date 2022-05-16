// https://leetcode.com/problems/counting-bits/
// Given an integer n, return an array ans of length 
// n + 1 such that for each i (0 <= i <= n), ans[i] is 
// the number of 1's in the binary representation of i.
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>v(n+1,0);
        for(int i=1;i<=n;i++){
            v[i]=1+v[i&(i-1)];
        }
        return v;
    }
};