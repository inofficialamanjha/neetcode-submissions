class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = -1;
        int j = nums.size();

        for(int pos=0; pos<j; pos++) {
            if (nums[pos]==0) {
                i++;
                swap(nums[i], nums[pos]);
            } else if (nums[pos]==1) {
                continue;
            } else {
                j--;
                swap(nums[j], nums[pos]);
                pos--;
            }
        }
    }
};