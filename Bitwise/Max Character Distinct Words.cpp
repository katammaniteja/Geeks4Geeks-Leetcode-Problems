// Given a list of lowercase alphabetical strings words, 
// return the maximum sum of the lengths of two distinct
//  words that don't share a common letter.
int solve(vector<string>& words) {
    vector<pair<int, int>> nums;
    int n = words.size();
    for (auto s : words) {
        int temp = 0;
        for (auto ch : s) {
            temp = temp | (1 << (ch - 'a'));
        }
        nums.push_back({temp, s.length()});
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int x1 = nums[i].first;
            int l1 = nums[i].second;
            int x2 = nums[j].first;
            int l2 = nums[j].second;
            if ((x1 & x2) == 0) {
                ret = max(ret, l1 + l2);
            }
        }
    }
    return ret;
}