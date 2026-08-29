class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // 1 2 3 4 5 6 7 8
        // Result: 8 7 6 1 2 3 4 5

        k = k%(nums.size());

        if(k==0)
            return;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin()+k, nums.end());
        reverse(nums.begin(), nums.begin()+k);
    }
};