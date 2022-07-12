// https://leetcode.com/problems/minimum-window-substring/
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(char &ch:t) mp[ch]++;
        int i=0,start=0,j=0,ans=INT_MAX,count=mp.size();
        while(j<s.size()){
            mp[s[j]]--;
            if(mp[s[j]]==0) count--;
            if(count==0){
                while(count==0){
                    if(ans>j-i+1){
                        ans=j-i+1;
                        start=i;
                    }
                    mp[s[i]]++;
                    if(mp[s[i]]>0) count++;
                    i++;
                }
            }
            j++;
        }
        if(ans==INT_MAX) return "";
        return s.substr(start,ans);
    }
};