class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int longestStart = 0;
        int longestLength = 1;

        for (int k = 0; k < n; k++) {
            for (int i = 0; i + k < n; i++) {

                if (k == 0) {
                    dp[i][i] = true;
                } else {
                    dp[i][i + k] = (s[i] == s[i + k]);

                    if (k > 1) {
                        dp[i][i + k] =
                            dp[i][i + k] &&
                            dp[i + 1][i + k - 1];
                    }
                }

                if (dp[i][i + k] && k + 1 > longestLength) {
                    longestStart = i;
                    longestLength = k + 1;
                }
            }
        }

        return s.substr(longestStart, longestLength);
    }
};