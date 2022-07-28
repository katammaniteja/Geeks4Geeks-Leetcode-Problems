// https://atcoder.jp/contests/dp/tasks/dp_b
// The change in the problem is frog can jump from one step to k steps.
void frog(int arr[],int n,int k){
    int dp[n];
    dp[0]=0;
    for(int i=1;i<n;i++){
        int a=INT_MAX;
        int b=k;
        for(int j=i-1;j>=0 && b>0;j--,b--){
            a=min(a,abs(arr[i]-arr[j])+dp[j]);
        }
        dp[i]=a;
    }
    cout<<dp[n-1];
}
