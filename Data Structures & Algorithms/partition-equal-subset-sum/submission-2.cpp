class Solution {
public:
    bool func(int i, vector<int>& nums, int target, vector<vector<int>> &dp) {
        if (i>=nums.size() || target < 0) {
            return false;
        }

        if (target==0) {
            return true;
        }

        if (dp[i][target]==-1) {
           dp[i][target] = func(i+1, nums, target - nums[i], dp) || func(i+1, nums, target, dp); 
        }

        return dp[i][target];
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (totalSum % 2 != 0) {
            return false;
        }
        int target = totalSum/2;
        vector<vector<int>> dp(nums.size(), vector<int>(target+1, -1));
        return func(0, nums, target, dp);
    }
};
