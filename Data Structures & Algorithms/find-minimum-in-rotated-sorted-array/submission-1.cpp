class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int u = nums.size() - 1;

        while(l<u) {
            int mid = l + (u-l)/2;
            cout<<nums[mid]<<" "<<l<<" "<<u<<endl;

            if (nums[mid]>=nums[l] && nums[mid]>=nums[u]) {
                l = mid+1; // Sure shot that the number is at the right
            } else if (nums[mid]<=nums[l] && nums[mid]<=nums[u]) {
                u = mid; // We are sure that the number is at where we are - but it can be the same one
            } else if (nums[mid]>=nums[l] && nums[mid]<=nums[u]) {
                return nums[l]; // it a increasing array
            } else {
                // nums[mid] <= nums[l] && nums[mind] >= nums[u] // not possible;
            }
        }

        return nums[l];
    }
};
