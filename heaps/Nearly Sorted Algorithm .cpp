// Given an array of n elements, where each element is at most k 
// away from its target position. The task is to print array in sorted form.

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n , k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0;i<n;i++)  cin>>arr[i];       
	    priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<=k && i<n;i++) pq.push(arr[i]);
        for(int i=k+1;i<n;i++){
            cout<<pq.top()<<" ";
            pq.pop();
            pq.push(arr[i]);
        }
        while(pq.size()){
            cout<<pq.top()<<" ";
            pq.pop();
        }
        cout<<endl;
	}
	return 0;
}