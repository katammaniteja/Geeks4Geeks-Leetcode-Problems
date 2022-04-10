#include<iostream>
using namespace std;
int main(){
    string text,pattern;
    cin>>text>>pattern;
    int m=text.size(),n=pattern.size();
    for(int i=0;i<=m-n;i++){
        int j;
        for(j=0;j<n;j++){
            if(text[i+j]!=pattern[j]) break;
        }
        if(j==n) cout<<i<<" ";
        if(j==0) i++;
        else i+=j;
    }
}