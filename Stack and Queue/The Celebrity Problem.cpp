// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& arr, int n) 
    {
        // code here 
        stack<int>s;
        for(int i=0;i<n;i++) s.push(i);
        while(s.size()>1){
            int a=s.top();
            s.pop();
            int b=s.top();
            if(arr[a][b]==0){
                s.pop();
                s.push(a);
            }
        }
        for(int i=0;i<=n-1;i++){
            if(i==s.top()) continue;
            if(arr[s.top()][i]!=0 || arr[i][s.top()]!=1) return -1;
        }
        return s.top();
    }
};