// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Given a string s, find the length of the longest substring without 
// repeating characters.

class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        unordered_set<char>s;
        unordered_set<char>::iterator it;
        int res=0,count=0;
        deque<int>dq;
        for(int i=0;i<str.length();i++){
            if(s.size()==0 || s.find(str[i])==s.end()){
                count++;
                s.insert(str[i]);
                dq.push_back(str[i]);
            }
            
            else{
                dq.push_back(str[i]);
                while(dq.front()!= str[i]){
                    count--;
                    s.erase(s.find(dq.front()));
                    dq.pop_front();
                }
                dq.pop_front();
            }
            res=max(res,count);
        }
        return res;
    }
};