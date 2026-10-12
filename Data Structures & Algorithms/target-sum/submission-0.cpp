class Solution {
public:
    unordered_map<int, unordered_map<int, int>> memo;

    int findTargetSumWays(vector<int>& nums, int target, int current = 0) {
        if (current == nums.size()) {
            if (target==0) {
                return 1;
            } else {
                return 0;
            }
        }

        if (memo.count(current) && memo[current].count(target)) {
            return memo[current][target];
        }

        memo[current][target] = 0;
        memo[current][target] += findTargetSumWays(nums, target + nums[current], current + 1);
        memo[current][target] += findTargetSumWays(nums, target - nums[current], current + 1);
        return memo[current][target];
    }
};
