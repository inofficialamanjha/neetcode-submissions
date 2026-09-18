class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> permute(vector<int>& nums) {
        generate(nums);
        return ans;
    }

    void generate(vector<int>& nums, int currentIndex = 0) {
        int size = nums.size();

        if (currentIndex == size) {
            ans.push_back(nums);
            return;
        }

        for(int i=currentIndex; i<size; i++) {
            swap(nums[currentIndex], nums[i]); // Do this
            generate(nums, currentIndex + 1);
            swap(nums[currentIndex], nums[i]); // Revert
        }
    }
};
