// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

// You are given N number of books. Every ith book has Ai number of pages. 
// You have to allocate contagious books to M number of students. There can 
// be many ways or permutations to do so. In each permutation, one of the M 
// students will be allocated the maximum number of pages. Out of all these 
// permutations, the task is to find that particular permutation in which 
// the maximum number of pages allocated to a student is minimum of those in 
// all the other permutations and print this minimum value. Each book will 
// be allocated to exactly one student. Each student has to be allocated at least one book.


class Solution 
{
    public:
    bool isAllocate(int arr[],int n,int mid,int m){
        int pages=0,students=1;
        for(int i=0;i<n;i++){
            if(arr[i]>mid) return false;
            if(pages+arr[i]>mid){
                pages=arr[i];
                students++;
            }
            else pages+=arr[i];
        }
        return (students<=m);
    }
    int findPages(int arr[], int n, int m) 
    {
        int low=arr[0],high=arr[0],res=-1;
        for(int i=1;i<n;i++){
            low=min(low,arr[i]);
            high+=arr[i];
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isAllocate(arr,n,mid,m)){
                res=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return res;
    }
};