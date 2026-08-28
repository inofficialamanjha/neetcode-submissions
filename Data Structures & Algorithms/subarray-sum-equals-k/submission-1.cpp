class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // [2, 1, 2, 4]
        vector<int> prefixSum(nums.size(), 0);

        for(int i=0; i<nums.size(); i++) {
            if (i==0) {
                prefixSum[i] = nums[i];
            } else {
                prefixSum[i] = prefixSum[i-1] + nums[i];
            }
        }

        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            if (prefixSum[i] == k) {
                count++;
            }

            for(int j=0; j<i; j++) {
                if (prefixSum[i] - prefixSum[j] == k) {
                    count++;
                }
            }
        }

        return count;
    }
};