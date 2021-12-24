#include<iostream>
using namespace std;
int Hoare(int arr[],int l,int r){
    int pivot=arr[l];
    int i=l-1,j=r+1;
    while(1){
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>=j) return j;
        swap(arr[i],arr[j]);
    }
}
void qSort(int arr[],int l,int r){
    if(l<r){
        int p=Hoare(arr,l,r);
        qSort(arr,l,p);
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