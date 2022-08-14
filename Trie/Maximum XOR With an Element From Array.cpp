// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
class Solution {
public:
    class Trie{
        public:
        Trie* child[2];
    };
    Trie* root=new Trie();
    void insert(int n){
        Trie* curr=root;
        for(int i=31;i>=0;i--){
            int bit=(n>>i)&1;
            if(curr->child[bit]==NULL) curr->child[bit]=new Trie();
            curr=curr->child[bit];
        }
    }
    int getMax(int n){
        Trie* curr=root;
        int ans=0;
        for(int i=31;i>=0;i--){
            int bit=(n>>i)&1;
            if(curr->child[1-bit]!=NULL){
                ans=ans+pow(2,i);
                curr=curr->child[1-bit];
            }
            else curr=curr->child[bit];
        }
        return ans;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        int n=queries.size();
        vector<int>ans(n,-1);
        vector<pair<int,pair<int,int>>>offlineQueries;
        for(int i=0;i<n;i++){
            offlineQueries.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(offlineQueries.begin(),offlineQueries.end());
        int ind=0;
        for(int i=0;i<n;i++){
            int a=offlineQueries[i].first,x=offlineQueries[i].second.first, qInd=offlineQueries[i].second.second;
            while(ind<nums.size() && nums[ind]<=a){
                insert(nums[ind]);
                ind++;
            }
            if(ind==0) ans[qInd]=-1;
            else ans[qInd]=getMax(x);
        }
        return ans;
    }
};