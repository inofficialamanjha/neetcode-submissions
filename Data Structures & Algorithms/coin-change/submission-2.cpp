class Solution {
public:
    vector<int> dp;

    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount + 1, -1);

        dp[0] = 0;

        int result = dfs(coins, amount);

        if (result==INT_MAX) {
            return -1;
        }
        
        return result;
    }

    int dfs(vector<int>& coins, int amount) {
        if (amount < 0) {
            return INT_MAX;
        }

        if (dp[amount] != -1) {
            return dp[amount];
        }

        int minCoins = INT_MAX;

        for (int coin : coins) {
            int result = dfs(coins, amount - coin);

            if (result != INT_MAX) {
                minCoins = min(minCoins, result + 1);
            }
        }

        if (minCoins == INT_MAX) {
            dp[amount] = INT_MAX;
        } else {
            dp[amount] = minCoins;
        }

        return dp[amount];
    }
};