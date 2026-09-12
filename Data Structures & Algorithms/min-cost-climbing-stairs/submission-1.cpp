class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> stairCost = vector<int>(cost.size()+1, 0);

        for(int i=2; i<stairCost.size(); i++) {
            stairCost[i] = min(stairCost[i-1] + cost[i-1], stairCost[i-2] + cost[i-2]);
        }

        return stairCost[cost.size()];
    }
};
