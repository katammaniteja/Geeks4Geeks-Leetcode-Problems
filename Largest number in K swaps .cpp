// https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1
// Given a number K and string str of digits denoting 
// a positive integer, build the largest number possible 
// by performing swap operations on the digits of str 
// at most K times.

class Solution{
    public:
    //Function to find the largest number after k swaps.
    void func(string &str,string &res,int k,int index){
        if(k==0) return;
        char ch=str[index];
        for(int i=index+1;i<str.length();i++){
            ch=max(ch,str[i]);
        }
        if(ch!=str[index]) k--;
        for(int i=index;i<str.length();i++){
            if(str[i]==ch){
                swap(str[i],str[index]);
                res=max(res,str);
                func(str,res,k,index+1);
                swap(str[i],str[index]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
       string res=str;
       func(str,res,k,0);
       return res;
    }
};