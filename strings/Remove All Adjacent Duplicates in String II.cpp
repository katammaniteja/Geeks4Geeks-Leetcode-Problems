// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>>vp;
        for(int i=0;i<s.size();i++){
            if(!vp.size() || vp.back().first!=s[i]) vp.push_back({s[i],1});
            else{
                if(vp.back().second==k-1) vp.pop_back();
                else{
                    int x=vp.back().second;
                    vp.pop_back();
                    vp.push_back({s[i],x+1});
                }
            }
        }
        string ans;
        for(int i=0;i<vp.size();i++){
            for(int j=0;j<vp[i].second;j++) ans+=vp[i].first;
        }
        return ans;
    }
};