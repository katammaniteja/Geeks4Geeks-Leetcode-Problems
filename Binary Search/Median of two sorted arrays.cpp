// https://leetcode.com/problems/median-of-two-sorted-arrays/

// Given two sorted arrays nums1 and nums2 of size m and n respectively,
//  return the median of the two sorted arrays.

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        if(n1>n2){
            swap(n1,n2);
            swap(nums1,nums2);
        }
        int begin=0,end=n1;
        while(begin<=end){
            int i1=begin+(end-begin)/2;
            int i2=(n1+n2+1)/2 -i1;
            int l1=(i1==0)?INT_MIN:nums1[i1-1];
            int l2=(i2==0)?INT_MIN:nums2[i2-1];
            int r1=(i1==n1)?INT_MAX:nums1[i1];
            int r2=(i2==n2)?INT_MAX:nums2[i2];

                if((n1+n2) %2==1) return (double)max(l1,l2);
                return (double)(max(l1,l2)+min(r1,r2))/2;
                
            }
            else if(l1>r2) end=i1-1;
            else begin=i1+1;
        }
        return 1;
    }
};