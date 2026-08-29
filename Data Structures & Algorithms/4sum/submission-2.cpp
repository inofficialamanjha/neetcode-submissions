class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                long long total = (long long)target - nums[i] - nums[j];

                int s = j + 1;
                int e = n - 1;

                while (s < e) {
                    long long sum = (long long)nums[s] + nums[e];

                    if (sum == total) {
                        ans.push_back({
                            nums[i],
                            nums[j],
                            nums[s],
                            nums[e]
                        });

                        s++;
                        e--;

                        while (s < e && nums[s] == nums[s - 1])
                            s++;

                        while (s < e && nums[e] == nums[e + 1])
                            e--;
                    }
                    else if (sum < total) {
                        s++;
                    }
                    else {
                        e--;
                    }
                }
            }
        }

        return ans;
    }
};