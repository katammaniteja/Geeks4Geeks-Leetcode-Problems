// Given a set of N jobs where each jobi has a deadline and profit associated with it.
// Each job takes 1 unit of time to complete and only one job can be scheduled at a
// time. We earn the profit associated with job if and only if the job is completed
// by its deadline. Find the number of jobs done and the maximum profit.
// Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.
vector<int> JobScheduling(Job arr[], int n)
{
    vector<pair<int, int>> vp1;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        vp1.push_back({arr[i].profit, arr[i].dead});
        res = max(res, arr[i].dead);
    }
    sort(vp1.begin(), vp1.end());
    int dp[res] = {0};
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = vp1[i].second - 1; j >= 0; j--)
        {
            if (dp[j] == 0)
            {
                dp[j] = vp1[i].first;
                break;
            }
        }
    }
    vector<int> v;
    v.push_back(0);
    v.push_back(0);
    for (int i = 0; i < res; i++)
    {
        if (dp[i] != 0)
            v[0]++;
        v[1] += dp[i];
    }
    return v;
}