// https://binarysearch.com/problems/Shortest-Sublist-to-Remove-to-Make-Sorted-List
int solve(vector<int>& nums) {
    int n=nums.size();
    if(n==0) return 0;
    int l=0,r=n-1;
    while(l<n-1 && nums[l]<=nums[l+1]) l++;
    if(l==n-1) return 0;
    while(r>0 && nums[r-1]<=nums[r]) r--;
    int i=0,j =r,res = min(n-l-1,r);
    while (i<=l && j< n) {
        if (nums[i] <= nums[j]) {
            res = min(res,j-i-1);
            i++;
        } else
            j++;
    }
    return res;
}