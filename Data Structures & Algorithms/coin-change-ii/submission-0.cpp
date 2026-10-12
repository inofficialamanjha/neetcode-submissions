class Solution {
public:
    unordered_map<int, unordered_map<int, int>> memo;

    int change(int amount, vector<int>& coins, int current = 0) {
        if (amount==0) {
            return 1;
        }

        if (amount < 0) {
            return 0;
        }

        if (current >= coins.size()) {
            return 0;
        }

        if (memo.count(amount) && memo[amount].count(current)) {
            return memo[amount][current];
        }

        // Either take the current - or do not
        memo[amount][current] = change(amount, coins, current + 1) + change(amount-coins[current], coins, current);
        return memo[amount][current];
    }
};

/**
change(4, 0) = change(4, 1) + change(3, 0)
= change(4, 2) + change(2, 1) + change(3, 1) + change(2, 0)
**/
