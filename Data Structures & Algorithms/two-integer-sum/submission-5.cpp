#define OFFSET 10000000

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> num_pos(2 * OFFSET + 1, -1);

        for (int i = 0; i < nums.size(); i++) {
            int pos = nums[i] + OFFSET;
            num_pos[pos] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int targetDiff = target - nums[i];
            int pos = targetDiff + OFFSET;

            if (pos >= 0 && pos < num_pos.size() &&
                num_pos[pos] != -1 &&
                num_pos[pos] != i) {
                return {i, num_pos[pos]};
            }
        }

        return {};
    }
};