// https://leetcode.com/problems/count-of-smaller-numbers-after-self/
class Solution {
public:
    void mergeSort(vector<pair<int,int>>&vp,vector<int>&ans,int l,int m,int r){
        int n1=m-l+1,n2=r-m;
        vector<pair<int,int>>left(n1),right(n2);
        for(int i=0;i<n1;i++) left[i]=vp[i+l];
        for(int i=0;i<n2;i++) right[i]=vp[m+1+i];
        int count=0,a=l,i=0,j=0;
        while(i<n1 && j<n2){
            if(left[i].first<=right[j].first){
                ans[left[i].second]+=count;
                vp[a++]=left[i++];
            }
            else{
                count++;
                vp[a++]=right[j++];
            }
        }
        while(i<n1){
            ans[left[i].second]+=count;
            vp[a++]=left[i++];
        }
        while(j<n2){
            vp[a++]=right[j++];
        }
    }
    void merge(vector<pair<int,int>>&vp,vector<int>&ans,int l,int r){
        if(l<r){
            int mid=l+(r-l)/2;
            merge(vp,ans,l,mid);
            merge(vp,ans,mid+1,r);
            mergeSort(vp,ans,l,mid,r);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++) vp.push_back({nums[i],i});
        vector<int>ans(n,0);
        merge(vp,ans,0,n-1);
        return ans;
    }
};