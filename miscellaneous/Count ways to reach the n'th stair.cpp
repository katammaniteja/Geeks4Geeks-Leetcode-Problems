// https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1
// There are n stairs, a person standing at the bottom wants to reach the top. 
// The person can climb either 1 stair or 2 stairs at a time. Count the number 
// of ways, the person can reach the top (order does matter).

class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        if(n==1 || n==2) return n;
        int64_t a=1,b=2;
        int mod=1e9 +7;
        for(int i=3;i<=n;i++){
            int temp=a;
            a=b,b+=temp;
            a=a%mod,b=b%mod;
        }
        return b%mod;
    }
};
