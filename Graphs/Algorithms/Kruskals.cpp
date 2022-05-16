#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,v,wt;
    node(int first,int second,int weight){
        u=first;
        v=second;
        wt=weight;
    }
};
int findPar(int u,vector<int>&parent){
    if(u==parent[u]) return u;
    return parent[u]=findPar(parent[u],parent);
}
void unionn(int u,int v,vector<int>&parent,vector<int>&rank){
    u=findPar(u,parent);
    v=findPar(v,parent);
    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[v]<rank[u]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}
bool comp(node a,node b){
    return a.wt<b.wt;
}
int main(){
    vector<node>edges;
    int v=5;
    edges.push_back(node(0,1,10));
    edges.push_back(node(1,3,15));
    edges.push_back(node(2,3,4));
    edges.push_back(node(2,0,6));
    edges.push_back(node(0,3,5)),
    sort(edges.begin(),edges.end(),comp);
    vector<int>parent(v);
    for(int i=0;i<v;i++) parent[i]=i;
    vector<int>rank(v,0);
    int cost=0;
    for(int i=0;i<v;i++){
        if(findPar(edges[i].u,parent)!=findPar(edges[i].v,parent)){
            cost+=edges[i].wt;
            unionn(edges[i].u,edges[i].v,parent,rank);
        }
    }
    cout<<cost<<endl;
}