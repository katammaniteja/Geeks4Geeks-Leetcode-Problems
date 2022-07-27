// https://leetcode.com/problems/4sum/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i!=0 && nums[i-1]==nums[i]) continue;
            for(int j=i+1;j<n;j++){
                if(j!=i+1 && nums[j-1]==nums[j]) continue;
                int left=j+1,right=n-1;
                while(left<right){
                    if(left!=j+1 && nums[left]==nums[left-1]){
                        left++;
                        continue;
                    }
                    if(right!=n-1 && nums[right]==nums[right+1]){
                        right--;
                        continue;
                    }
                    int total=nums[left]+nums[right]+nums[i]+nums[j];
                    if(total==target){
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                    }
                    else if(total>target) right--;
                    else left++;
                }
            }
        }
        return ans;
    }
};