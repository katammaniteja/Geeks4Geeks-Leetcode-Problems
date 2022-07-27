// https://leetcode.com/problems/longest-happy-prefix/
class Solution {
public:
    string longestPrefix(string str) {
        int n=str.size();
        vector<int>lps(n);
        lps[0]=0;
        for(int i=1;i<n;i++){
            int len=lps[i-1];
            if(str[i]==str[len]) lps[i]=1+lps[i-1];
            else{
                if(len==0) lps[i]=0;
                while(len>0 && str[i]!=str[len]) len=lps[len-1];
                if(str[i]==str[len]) lps[i]=1+len;
                else lps[i]=0;
            }
        }
        return str.substr(0,lps[n-1]);
    }
};