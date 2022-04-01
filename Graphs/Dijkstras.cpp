#include<bits/stdc++.h>
using namespace std;
vector<int> Dijkstras(vector<vector<int>>graph,int v,int src){
    vector<int>dist(v,INT_MAX);
    dist[src]=0;
    vector<bool>fin(v,false);
    for(int count=0;count<v-1;count++){
        int u=-1;
        for(int i=0;i<v;i++){
            if(!fin[i] &&(u==-1 || dist[i]<dist[u]))  u=i;
        }
        fin[u]=true;
        for(int i=0;i<v;i++){
            if(graph[u][i]!=0 && !fin[i]){
                dist[i]=min(dist[i],dist[u]+graph[u][i]);
            }
        }
    }
    return dist;
}
int main(){
    vector<vector<int>>graph={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    vector<int>dist=Dijkstras(graph,9,0);
    for(int x:dist) cout<<x<<" ";
}