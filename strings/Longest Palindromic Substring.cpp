// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string1956/1/
class Solution{   
public:
    string longestPalindrome(string str){
        // code here 
        string res=str.substr(0,1);
        for(int i=0;i<str.length();i++){
            int j=i,k=i;
            while(j>=0 && k<str.length() && str[k]==str[j]){
                if(res.length()<k-j+1) res=str.substr(j,k-j+1);
                j--,k++;
            }
            j=i;k=i+1;
            while(j>=0 && k<str.length() && str[k]==str[j]){
                if(res.length()<k-j+1) res=str.substr(j,k-j+1);
                j--,k++;
            }
        }
        return res;
    }
};