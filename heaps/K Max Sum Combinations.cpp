// https://www.codingninjas.com/codestudio/problems/k-max-sum-combinations_975322
#include<bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    priority_queue<pair<int,pair<int,int>>>pq;
    set<pair<int,int>>s;
    int i=n-1,j=n-1;
    pq.push({a[i]+b[j],{i,j}});
    s.insert({i,j});
    vector<int>ans;
    for(int count=0;count<k;count++){
        auto tp=pq.top();
        pq.pop();
        ans.push_back(tp.first);
        i=tp.second.first,j=tp.second.second;
        if(s.find({i-1,j})==s.end()){
            pq.push({a[i-1]+b[j],{i-1,j}});
            s.insert({i-1,j});
        }
        if(s.find({i,j-1})==s.end()){
            pq.push({a[i]+b[j-1],{i,j-1}});
            s.insert({i,j-1});
        }
    }
    return ans;
}