// https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/0

// Dilpreet wants to paint his dog's home that has n boards with different 
// lengths. The length of ith board is given by arr[i] where arr[] is an 
// array of n integers. He hired k painters for this work and each painter 
// takes 1 unit time to paint 1 unit of the board. 
// The problem is to find the minimum time to get this job done if all 
// painters start together with the constraint that any painter will only 
// paint continuous boards, say boards numbered {2,3,4} or only board {1} 
// or nothing but not boards {2,4,5}.

class Solution
{
  public:
    bool isPossible(int arr[],int n,int k,long long target){
        int i=0;
        while(i<n){
            long long a=target;
            while(a>=arr[i]){
                a-=arr[i];
                i++;
            }
            k--;
        }
        return (k>=0);
    }
    long long minTime(int arr[], int n, int k)
    {
        long long res=0, l=0,r,mid;
        for(int i=0;i<n;i++){ res+=arr[i];
        l=max(l,(long long)arr[i]);
        }
        r=res;
        while(l<=r){
            mid=l+(r-l)/2;
            if(isPossible(arr,n,k,mid)){
                res=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return res;
    }
};