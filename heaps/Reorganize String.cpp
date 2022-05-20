// https://leetcode.com/problems/reorganize-string/
// Given a string s, rearrange the characters of s so that 
// any two adjacent characters are not the same. Return any 
// possible rearrangement of s or return "" if not possible.
class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>,vector<pair<int,char>>>pq;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++) mp[s[i]]++;
        for(auto it=mp.begin();it!=mp.end();it++){
            pq.push({(*it).second,(*it).first});
        }
        string ans;
        while(pq.size()){
            auto x=pq.top();
            pq.pop();
            if(ans.size() && ans.back()==x.second){
                if(pq.size()){
                    auto y=pq.top();
                    pq.pop();
                    ans+=y.second;
                    pq.push(x);
                    y.first--;
                    if(y.first) pq.push(y);
                }
                else return "";
            }
            else{
                ans+=x.second;
                x.first--;
                if(x.first) pq.push(x);
            }
        }
        return ans;
    }
};