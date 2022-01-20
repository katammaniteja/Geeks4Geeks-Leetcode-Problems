// https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1
// Given an input stream of N integers. The task is to insert these numbers into a new 
// stream and find the median of the stream formed by each insertion of X to the new stream.
class Solution
{
    public:
    //Function to insert heap.
    double ans;
    priority_queue<int>s;
    priority_queue<int,vector<int>,greater<int>>g;
    void insertHeap(int &x)
    {
        if(s.size()==0){
            s.push(x);
            ans=x;
            return;
        }
        if(s.size()>g.size()){
            if(s.top()>x){
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else g.push(x);
            ans=double(s.top()+g.top())/2;
        }
        else{
            if(x<=s.top()) s.push(x);
            else {
                g.push(x);
                s.push(g.top());
                g.pop();
            }
            ans=s.top();
        }
    }
    //Function to return Median.
    double getMedian()
    {
        return ans;
    }
};