int prims(vector<int>graph,int v){
    int key[v],res=0;
    fill(key,key+v,INT_MAX);
    key[0]=0;
    bool mSet[v]={false};
    for(int count=0;count<v;count++){
        int u=-1;
        for(int i=0;i<v;i++){
            if(!mSet[i] &&(u==-1 || key[i]<key[u])) u=i;
        }
        mSet[u]=true;
        res+=key[u];
        for(int j=0;j<v;j++){
            if(graph[u][j]!=0 && !mSet[j]) key[j]=min(key[j],key[u][j]);
        }
        return res;
    }
}