class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        int* dp = new int[n];

        dp[n-1] = 1;

        for(int i = n-2; i >= 0; i--) {
            dp[i] = 1;

            for(int j = i+1; j < n; j++) {
                if(nums[i] < nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        int ans = 1;

        for(int i = 0; i < n; i++) {
            cout << dp[i] << " ";
            ans = max(ans, dp[i]);
        }

        delete[] dp;

        return ans;
    }
};