class Solution {
public:
    unordered_map<int, int> dp;

    int jump(vector<int>& nums, int current = 0) {
        if (current == nums.size() - 1) {
            return 0;
        }

        if (nums[current]==0) {
            return INT_MAX; // We can't jump further from here
        }

        if (dp.count(current)) {
            return dp[current];
        }

        int ans = INT_MAX;

        for (int gap = 1; gap<=nums[current]; gap++) {
            int j = current + gap;
            if (j < nums.size()) {
                int steps = jump(nums, j);
                if (steps == INT_MAX) {
                    continue; // Further iteration is not possible
                } else {
                    ans = min(ans, steps + 1); // One more step from the next jump
                }
            }
        }

        dp[current] = ans;
        return ans;
    }
};
