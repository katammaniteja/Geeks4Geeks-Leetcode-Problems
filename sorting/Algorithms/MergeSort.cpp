
#include<iostream>
using namespace std;
void merge(int arr[],int l,int m,int r){
    int n1=m-l+1,n2=r-m;
    int left[n1];
    int right[n2];
    for(int i=0;i<n1;i++) left[i]=arr[i+l];
    for(int i=0;i<n2;i++) right[i]=arr[m+i+1];
    int a=l,i=0,j=0;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]) arr[a++]=left[i++];
        else arr[a++]=right[j++];
    }
    for( ;i<n1;i++)
        arr[a++]=left[i];
    for( ;j<n2;j++)
        arr[a++]=right[j];   
}
void mergesort(int arr[],int l,int r){
    if(r>l){
        int m=l+ (r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}