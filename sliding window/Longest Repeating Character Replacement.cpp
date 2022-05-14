// https://leetcode.com/problems/longest-repeating-character-replacement/
// You are given a string s and an integer k. You can choose any character of 
// the string and change it to any other uppercase English character. You can 
// perform this operation at most k times. Return the length of the longest substring 
// containing the same letter you can get after performing the above operations.
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxf=0,ans=0;
        int count[26]={0};
        int i=0;
        for(int j=0;j<s.size();j++){
            maxf=max(maxf,++count[s[j]-'A']);
            if(j-i+1>maxf+k){
                count[s[i]-'A']--;
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};