// https://practice.geeksforgeeks.org/problems/find-sum-of-different-corresponding-bits-for-all-pairs4652/1

// We define f (X, Y) as number of different corresponding bits in
//  binary representation of X and Y. For example, f (2, 7) = 2, since
// binary representation of 2 and 7 are 010 and 111, respectively.
//  The first and the third bit differ, so f (2, 7) = 2.

class Solution{
public:
    int countBits(int n, long long int arr[])
    {
        long long int res=0;
        for(int i=0;i<32;i++){
            long long int count=0;
            for(int j=0;j<n;j++){
                if((arr[j]&1)==1) count++;
                arr[j]=arr[j]>>1;
            }
            res+=2*count*(n-count);
        }
        return res%1000000007;
    }
};
