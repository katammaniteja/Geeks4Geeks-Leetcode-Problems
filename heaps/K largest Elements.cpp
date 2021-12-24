class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    priority_queue<int,vector<int>,greater<int>>pq(arr,arr+k);
	    for(int i=k;i<n;i++){
	        if(arr[i]>pq.top()){
	            pq.pop();
	            pq.push(arr[i]);
	        }
	    }
	    vector<int>v;
	    while(pq.size()){
	        v.push_back(pq.top());
	        pq.pop();
	    }
	    reverse(v.begin(),v.end());
	    return v;
	}
};