// https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        unordered_map<char,int>mp;
        int ans=0;int begin=0,i;
        for(i=0;i<str.length();i++){
            if((mp.find(str[i])!=mp.end()) && mp[str[i]]>=begin){
                while(str[begin]!=str[i]) begin++;
                begin++;
            }
            mp[str[i]]=i;
            ans=max(ans,i-begin+1);
        }
        return ans;
    }
};