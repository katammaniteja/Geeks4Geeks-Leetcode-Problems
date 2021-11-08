// https://practice.geeksforgeeks.org/problems/rank-the-permutations2323/1#


class Solution{
public:
    int mod=1000003;
    int fact(int n){
        int64_t res=1;
        for(int i=1;i<=n;i++)
            res=((res%mod)*i)%mod;
        return res%mod;
    }
    int rank(string str){
        int n=str.length();
        int64_t mul=fact(n);
        int count[256]={0};
        for(int i=0;i<n;i++) count[str[i]]++;
        for(int i=1;i<256;i++) count[i]+=count[i-1];
        int64_t res=1;
        for(int i=0;i<n-1;i++){
            mul=mul/(n-i);
            res=res+((count[str[i]]-1)*mul)%mod;
            for(int j=str[i];j<256;j++) count[j]--;
        }
        return res%mod;
    }
};