class Solution {
public:
    unordered_map<int, int> memo;

    int maxProfit(vector<int>& prices) {
        return dp(prices);
    }

    int dp(vector<int>& prices, int current = 0) {
        if (current >= prices.size()) {
            return 0;
        }

        int maxProfit = 0;

        if (memo.count(current)) {
            return memo[current];
        }

        // Take this Neetcoin
        for(int i=current+1; i<prices.size(); i++) {
            int profit = prices[i] - prices[current];
            int maxCurrProfit = profit + dp(prices, i+2); // Skip Two
            maxProfit = max(maxCurrProfit, maxProfit);
        }

        // Or, Ignore this Neetcoint
        memo[current] = max(maxProfit, dp(prices, current+1));
        return memo[current];
    }
};

/**
f(1..N) = {
1. I take this Neetcoin, if I donot have a neetcoin now
2. If I have a neetcoin, I can sell that neetcond + f(..3..N)
3. Ignore this neetcoind, f(.2..N)
}
**/
