class Solution {
public:
    vector<vector<int>> ans;
    vector<int> backtrack;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        func(nums, target);
        return ans;
    }

    void func(vector<int>& nums, int target, int pos=0) {
        if (target==0) {
            ans.push_back(backtrack);
            return;
        }

        if (pos>=nums.size()) {
            return;
        }

        if (nums[pos] > target) {
            return;
        }

        int limit = target / nums[pos];
        for(int i=0; i<=limit; i++) {

            for(int j=i; j>0; j--) {
                backtrack.push_back(nums[pos]); // Adding them
            }

            func(nums, target - (nums[pos]*i), pos + 1);

            for(int j=i; j>0; j--) {
                backtrack.pop_back(); // Removing them
            }
        }
    }
};
