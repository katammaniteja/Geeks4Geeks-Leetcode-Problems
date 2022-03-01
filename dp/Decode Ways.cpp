// https://leetcode.com/problems/decode-ways/
class Solution {
public:
    int numDecodings(string s) {
        int a=1,b=0;
        if(s[0]!='0') b=1;
        for(int i=1;i<s.size();i++){
            int temp=0;
            if(s[i]>'0'){
                temp=b;
            }
            if(s[i-1]=='1' ||(s[i-1]=='2' && s[i]<='6')) temp+=a;
            a=b;
            b=temp;
        }
        return b;
    }
};