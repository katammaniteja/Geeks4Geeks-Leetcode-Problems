class Solution {
public:
    int helper(vector<int>&tail,int key){
        return lower_bound(tail.begin(),tail.end(),key)-tail.begin();
    }
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int>tail;
        tail.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(arr[i]>tail.back()) tail.push_back(arr[i]);
            else{
                tail[helper(tail,arr[i])]=arr[i];
            }
        }
        return tail.size();
    }
};