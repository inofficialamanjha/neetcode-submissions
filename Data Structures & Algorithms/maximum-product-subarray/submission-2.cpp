class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int globalMax = nums[0];
        int currentMax = nums[0];
        int currentMin = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int mul1 = currentMax * nums[i];
            int mul2 = currentMin * nums[i];

            currentMax = max({nums[i], mul1, mul2});
            currentMin = min({nums[i], mul1, mul2});

            globalMax = max(globalMax, currentMax);
        }

        return globalMax;
    }
};