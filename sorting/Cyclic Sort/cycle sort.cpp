 #include<bits/stdc++.h>
using namespace std;
void cycleSort(vector<int>&v){
    int n=v.size();
    int i=0;
    while(i<n){
        if(v[i]==i+1) i++;
        else{
            swap(v[i],v[v[i]-1]);
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cycleSort(v);
    for(int x:v) cout<<x<<" ";
}