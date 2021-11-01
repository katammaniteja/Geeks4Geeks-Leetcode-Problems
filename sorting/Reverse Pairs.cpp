// https://leetcode.com/problems/reverse-pairs/
// Given an integer array nums, return the number of reverse pairs in the array.
// A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

class Solution {
public:
    int merge(vector<int>& nums,int l,int m,int r){
        int cnt=0;
        int j=m+1;
        for(int i=l;i<=m;i++){
            while(j<=r && nums[i]>2LL*nums[j]) j++;
            cnt+=(j-(m+1));
        }
        int n1=m-l+1,n2=r-m;
        int left[n1]; int right[n2];
        for(int i=0;i<n1;i++) left[i]=nums[i+l];
        for(int i=0;i<n2;i++) right[i]=nums[i+m+1];
        int a=l,i=0;j=0;
        while(i<n1 && j<n2){
            if(left[i]<=right[j]) nums[a++]=left[i++];                  
            else nums[a++]=right[j++];
        }
        for( ;i<n1;i++) nums[a++]=left[i];
        for( ;j<n2;j++) nums[a++]=right[j];
        return cnt;
    }
    int mergeSort(vector<int> & nums,int l,int r){
        int cnt=0;
        if(l<r){
            int m=l+ (r-l)/2;
            cnt+=mergeSort(nums,l,m);
            cnt+=mergeSort(nums,m+1,r);
            cnt+=merge(nums,l,m,r);
        }
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};
