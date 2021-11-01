// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

// Given an array nums of n integers where nums[i] is in the range [1, n], return 
// an array of all the integers in the range [1, n] that do not appear in nums.

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& v) {
        int i=0,n=v.size();
        vector<int>ans;
        while(i<n){
            if(v[i]==i+1) i++;
            else{
                if(v[i]==v[v[i]-1]) i++;
                else swap(v[i],v[v[i]-1]);
            }
        }
        for(int i=0;i<v.size();i++){
            if(v[i]!=i+1) ans.push_back(i+1);
        }
        return ans;
    }
};