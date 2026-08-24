class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<pair<int, int>> muls(nums.size(), {1,1});

        // Calculating Left Mul
        for(int i=1; i<nums.size(); i++) {
            muls[i].first = (muls[i-1].first)*nums[i-1];
        }

        // Calculating Right Mul
        for(int i=nums.size() - 2; i>=0 ;i--) {
            muls[i].second = (muls[i+1].second)*nums[i+1];
        }

        vector<int> ans(nums.size(), -1);
        for(int i=0; i<nums.size(); i++) {
            ans[i] = muls[i].first * muls[i].second;
        }

        return ans;
    }
};
