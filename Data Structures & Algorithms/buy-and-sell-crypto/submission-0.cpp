class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int maxHeight = prices[prices.size()-1];
        for(int i=prices.size()-2; i>=0; i--) {
            if (maxHeight > prices[i]) {
                profit = max(profit, maxHeight - prices[i]);
            }
            maxHeight = max(maxHeight, prices[i]);
        }
        return profit;
    }
};
