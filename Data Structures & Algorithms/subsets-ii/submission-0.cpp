class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        generate(nums);
        return ans;
    }

    void generate(vector<int>& nums, int pos = 0) {
        if (pos==nums.size()) {
            ans.push_back(subset);
            return;
        }

        int e = pos;
        while(e<nums.size() && nums[e]==nums[pos]) {
            e++;
        }

        generate(nums, e); // First generate skipping all nums[pos]

        // Then take then one by one
        for(int i=pos; i<e; i++) {
            for(int j=i; j<e; j++) {
                subset.push_back(nums[pos]);
            }
            generate(nums, e);
            for(int j=i; j<e; j++) {
                subset.pop_back();
            }
        }
    }
};
