// https://leetcode.com/problems/next-greater-element-i/

// The next greater element of some element x in an array is the first 
// greater element that is to the right of x in the same array.

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums, vector<int>& arr) {
        int n=arr.size();
        vector<int>v;
        v.push_back(-1);
        stack<int>s;
        s.push(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            while(s.size()>0 && arr[i]>=s.top()) s.pop();
            if(s.size()) v.push_back(s.top());
            else v.push_back(-1);
            s.push(arr[i]);
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<n;j++){
                if(arr[j]==nums[i]){
                    nums[i]=v[j];
                    break;
                }
            }
        }
        return nums;
    }
};