class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                dp[i][j] = (text1[i] == text2[j]) ? 1 : 0;

                if (i+1<m && j+1<n) {
                    dp[i][j] += dp[i+1][j+1];
                }

                if (i+1<m && j<n) {
                    dp[i][j] = max(dp[i][j], dp[i+1][j]);
                }

                if (i<m && j+1<n) {
                    dp[i][j] = max(dp[i][j], dp[i][j+1]);
                }
            }
        }

        return dp[0][0];
    }
};

/**
f(i, j) = if (f[i]==f[j]) then 1 + f(i+1, j+1) else f(i+1, j) else f(i, j+1) by else we mean max
**/
