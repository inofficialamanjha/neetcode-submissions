
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr(n + 2, 1);

        for (int i = 0; i < n; i++) {
            arr[i + 1] = nums[i];
        }

        vector<vector<int>> dp(
            n + 2, vector<int>(n + 2, 0)
        );

        // gap = distance between the two boundaries
        for (int gap = 2; gap <= n + 1; gap++) {
            for (int l = 0; l + gap <= n + 1; l++) {
                int r = l + gap;

                for (int k = l + 1; k < r; k++) {
                    int coins = dp[l][k]
                              + dp[k][r]
                              + arr[l] * arr[k] * arr[r];

                    dp[l][r] = max(dp[l][r], coins);
                }
            }
        }

        return dp[0][n + 1];
    }
};
