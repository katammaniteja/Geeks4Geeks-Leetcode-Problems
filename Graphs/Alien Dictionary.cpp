// https://practice.geeksforgeeks.org/problems/alien-dictionary/1
class Solution{
    public:
    string findOrder(string dict[], int n, int k) {
        //code here
        vector<vector<int>>lis(k);
        vector<int>indegree(k,0);
        for(int i=0;i<n-1;i++){
            for(int j=0;j<min(dict[i].size(),dict[i+1].size());j++){
                if(dict[i][j]==dict[i+1][j]) continue;
                lis[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                indegree[dict[i+1][j]-'a']++;
                break;
            }
        }
        string ans;
        queue<int>q;
        for(int i=0;i<k;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(q.size()){
            int tp=q.front();
            q.pop();
            ans+=char(tp+'a');
            for(int x:lis[tp]){
                indegree[x]--;
                if(indegree[x]==0) q.push(x);
            }
        }
        return ans;
    }
};