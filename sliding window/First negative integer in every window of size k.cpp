// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

// You don't need to read input or print anything. Your task is to 
// complete the function printFirstNegativeInteger() which takes the 
// array A[], its size N and an integer K as inputs and returns the 
// first negative number in every window of size K starting from the 
// first till the end. If a window does not contain a negative integer , 
// then return 0 for that window.

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k) {
                        
            vector<long long>v;
            deque<long long>dq;
            for(long long  i=0;i<k;i++){
                if(arr[i]<0) dq.push_back(i);
            }
            if(dq.size()==0) v.push_back(0);
            else v.push_back(arr[dq.front()]);
            for(long long i=k;i<n;i++){
                if(arr[i]<0) dq.push_back(i);
                while(dq.size() && dq.front()<=i-k) dq.pop_front();
                if(dq.size()==0) v.push_back(0);
                else v.push_back(arr[dq.front()]);
            }
            return v;
}