
class Solution {
public:
    unordered_map<int, unordered_map<int, int>> dp;

    bool isMatch(string s, string p, int i = 0, int j = 0) {
        if (j == p.size()) {
            return i == s.size();
        }

        if (dp.count(i) && dp[i].count(j)) {
            return dp[i][j];
        }

        bool ans = false;

        bool firstMatch = i < s.size() &&
            (p[j] == '.' || p[j] == s[i]);

        if (j + 1 < p.size() && p[j + 1] == '*') {
            // Zero occurrences
            ans = isMatch(s, p, i, j + 2);

            // One or more occurrences
            if (firstMatch) {
                ans = ans || isMatch(s, p, i + 1, j);
            }
        } else if (firstMatch) {
            ans = isMatch(s, p, i + 1, j + 1);
        }

        dp[i][j] = ans;
        return ans;
    }
};
