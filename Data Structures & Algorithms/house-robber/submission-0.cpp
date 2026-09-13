class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        int globalMax = 0;

        for(int i=1; i<=n; i++) {
            dp[i] = nums[i-1];

            if (i>2) {
                // either they will jump from 2 blocks way, or 3 blocks away
                dp[i] = max(dp[i], dp[i-2] + nums[i-1]);
                dp[i] = max(dp[i], dp[i-3] + nums[i-1]);
            }

            globalMax = max(globalMax, dp[i]);
        }

        return globalMax;
    }
};
