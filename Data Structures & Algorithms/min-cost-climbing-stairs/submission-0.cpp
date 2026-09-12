class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> stairCost = vector<int>(cost.size()+1, 0);

        for(int i=2; i<stairCost.size(); i++) {
            int prev1 = stairCost[i-1];
            int prev2 = stairCost[i-2];

            stairCost[i] = min(prev1 + cost[i-1], prev2 + cost[i-2]);
        }

        return stairCost[cost.size()];
    }
};
