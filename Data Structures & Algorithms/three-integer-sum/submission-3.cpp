class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> indices;

        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size()-2; i++) {
            if (i>0 && nums[i-1]==nums[i]) {
                continue; // duplicate number
            }

            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    indices.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    while(left<right && nums[left]==nums[left-1])
                        left++;
                    
                    while(left<right && nums[right+1]==nums[right])
                        right--;

                } else if (sum>0) {
                    right--;
                } else {
                    left++;
                }
            }
        }

        return indices;
    }
};
