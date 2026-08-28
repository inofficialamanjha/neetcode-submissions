class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSum;
        int count = 0, prefix = 0;

        prefixSum[prefix] = 1; // [] array

        for(auto& num: nums) {
            prefix += num;

            if(prefixSum.count(prefix - k)) {
                count += prefixSum[prefix-k];
            }

            prefixSum[prefix]++;
        }

        return count;
    }
};