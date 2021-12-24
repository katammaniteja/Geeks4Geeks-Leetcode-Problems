#include<iostream>
using namespace std;
int Lomuto(int arr[],int l,int r){
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<=r-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}
void qSort(int arr[],int l,int r){
    if(r>l){
        int p=Lomuto(arr,l,r);
        qSort(arr,l,p-1);
        qSort(arr,p+1,r);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
       cin>>arr[i];
    qSort(arr,0,n-1);
    for(int i=0;i<n;i++)
       cout<<arr[i]<<" ";
}