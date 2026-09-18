class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> combinations;

        int n = pow(2, nums.size());

        for(int i=0; i<n; i++) {
            // i represents a combination
            int num = i;
            vector<int> ans;
            for(int j=0; j<nums.size(); j++) {
                if (num & 1) {
                    ans.push_back(nums[j]);
                }
                num = num>>1;
            }
            combinations.push_back(ans);
        }

        return combinations;
    }
};
