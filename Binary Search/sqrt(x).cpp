// https://leetcode.com/problems/sqrtx/
// Given a non-negative integer x, compute and return the square root of x.

class Solution {
public:
    int mySqrt(int x) {
        int l=0,r=x,ans=-1;;
        while(l<=r){
            int64_t mid=l+(r-l)/2;
            if(x==mid*mid) return mid;
            else if(x>mid*mid){
                l=mid+1;
                ans=mid;
            }
            else r=mid-1;
        }
        return ans;
    }
};