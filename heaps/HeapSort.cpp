#include<iostream>
using namespace std;
void heapify(int arr[],int n,int i){
	int largest=i,left=2*i+1,right=2*i+2;
	if(left<n && arr[left]>arr[largest]) largest=left;
	if(right<n && arr[right]>arr[largest]) largest=right;
	if(largest!=i){
		swap(arr[largest],arr[i]);
		heapify(arr,n,largest);
	}
}
void buildHeap(int arr[],int n){
	for(int i=(n/2)-1;i>=0;i--){
		heapify(arr,n,i);
	}
}
void heap_sort(int arr[],int n){
	buildHeap(arr,n);
	for(int i=n-1;i>=1;i--){
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}
}
void print(int arr[],int n){
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	cout<<endl;
}
int main(){
	int n;
	cout<<"Enter the number of elements: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements: ";
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<"The elements before sorting are: ";
	print(arr,n);
	heap_sort(arr,n);
	cout<<"The elements after sorting are: ";
	print(arr,n);
	return 0;
}