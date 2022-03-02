// https://leetcode.com/problems/car-pooling/
class Solution {
public:
    bool carPooling(vector<vector<int>>& arr, int capacity) {
        vector<pair<int,int>>vp;
        for(int i=0;i<arr.size();i++){
            vp.push_back({arr[i][1],arr[i][0]});
            vp.push_back({arr[i][2],-arr[i][0]});
        }
        sort(vp.begin(),vp.end());
        int filled=0;
        for(int i=0;i<vp.size();i++){
            filled+=vp[i].second;
            if(filled>capacity) return false;
        }
        return true;
    }
};