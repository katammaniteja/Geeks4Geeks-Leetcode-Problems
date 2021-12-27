// Given weights and values of N items, we need to put these
// items in a knapsack of capacity W to get the maximum total
// value in the knapsack.
double fractionalKnapsack(int W, Item arr[], int n)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({arr[i].value, arr[i].weight});
    }
    sort(v.begin(), v.end(), mycamp);
    double d = 0;
    for (int i = 0; i < n && W > 0; i++)
    {
        if (W >= v[i].second)
        {
            W -= v[i].second;
            d += v[i].first;
        }
        else
        {
            d += (double)W * (v[i].first) / (double)(v[i].second);
            W = 0;
        }
    }
    return d;
}