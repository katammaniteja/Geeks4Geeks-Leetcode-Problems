// https://binarysearch.com/room/Dining-Philosophers-UX7uS1vD6s
// You are given a lowercase alphabet string s. Return the minimum 
// numbers of contiguous substrings in which s must be broken into 
// such that each substring is either non-increasing or non-decreasing.
int solve(string s) {
    if (s.empty()) return 0;
    int ans = 1;
    bool inc = false, dec = false;
    for (int i = 1; i < s.size(); i++) {
        if (!inc && !dec) {
            if (s[i] < s[i - 1])
                dec = true;
            else if (s[i] > s[i - 1])
                inc = true;
        }
        if (s[i] > s[i - 1] && dec) {
            inc = dec = false;
            ans++;
        } else if (s[i] < s[i - 1] && inc) {
            inc = dec = false;
            ans++;
        }
    }
    return ans;
}