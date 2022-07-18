// https://leetcode.com/problems/longest-consecutive-sequence/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        if(nums.size()==0) return 0;
        for(int i=0;i<nums.size();i++) s.insert(nums[i]);
        int res=1;
        for(int i=0;i<nums.size();i++){
            int count=1;
            if(s.find(nums[i]-1)==s.end()){
                int a=nums[i];
                while(s.find(a+1)!=s.end()) {count++;a++;}
                res=max(res,count);
            }
        }
        return res;
    }
};