class Solution {
public:
    int totalXORSum = 0;
    int subsetXORSum(vector<int>& nums) {
        subsetXORSum(nums, 0, 0);
        return totalXORSum;
    }

    void subsetXORSum(vector<int>& nums, int currentIndex, int currentXOR) {
        if (currentIndex==nums.size()) {
            totalXORSum += currentXOR;
            return;
        }

        subsetXORSum(nums, currentIndex + 1, currentXOR ^ nums[currentIndex]);
        subsetXORSum(nums, currentIndex + 1, currentXOR);
    }

};