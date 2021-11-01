// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Given a string containing digits from 2-9 inclusive, return all possible letter 
// combinations that the number could represent. Return the answer in any order.

class Solution {
public:
    void recus(vector<string>&ans,string str,string curr="",int i=0){
        if(i==str.length()){
            ans.push_back(curr);
            return;
        }
        int num=str[i]-48;
        int beg=(num-2)*3;
        int end=beg+2;
        if(num==7 || num==8 || num==9) end++;
        if(num==8 || num==9) beg++;
        if(num==9) end++;
        for(int j=beg;j<=end;j++)  recus(ans,str,curr+(char)('a'+j),i+1);
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0) return ans;
        recus(ans,digits);
        return ans;
    }
};