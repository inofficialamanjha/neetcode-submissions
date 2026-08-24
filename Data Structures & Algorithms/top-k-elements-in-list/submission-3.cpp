class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int num : nums)
            ++freq[num];

        vector<vector<int>> bucket(nums.size() + 1);

        for (const auto& [num, count] : freq)
            bucket[count].push_back(num);

        vector<int> result;
        result.reserve(k);

        for (int i = nums.size(); i > 0; --i) {
            for (int num : bucket[i]) {
                result.push_back(num);

                if (result.size() == k)
                    return result;
            }
        }

        return result;
    }
};