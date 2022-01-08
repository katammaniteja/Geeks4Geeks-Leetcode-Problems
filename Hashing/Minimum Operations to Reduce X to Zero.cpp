// You are given an integer array nums and an integer x. 
// In one operation, you can either remove the leftmost 
// or the rightmost element from the array nums and 
// subtract its value from x. Note that this modifies 
// the array for future operations. Return the minimum 
// number of operations to reduce x to exactly 0 if it 
// is possible, otherwise, return -1.
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int sum=0,res=INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==x) res=min(res,i+1);
            mp[sum]=i;
        }
        sum=0;
        for(int i=nums.size()-1;i>=0;i--){
            sum+=nums[i];
            if(sum==x) res=min(res,n-i);
            if(mp.find(x-sum)!=mp.end() && mp[x-sum]<i){
                res=min(res,mp[x-sum]+1+n-i);
            }
        }
        if(res==INT_MAX) return -1;
        return res;
    }
};