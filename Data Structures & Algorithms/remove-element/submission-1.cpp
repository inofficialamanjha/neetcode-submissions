class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int r = nums.size()-1;
        int f = 0;

        while(f<=r) {
            if(nums[f]==val) {
                swap(nums[f], nums[r]);
                r--; // Move the rear backward
            } else {
                f++; // Move front forward
            }
        }

        return r + 1;
    }
};