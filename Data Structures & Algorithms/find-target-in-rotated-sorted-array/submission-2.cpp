class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int u = nums.size() - 1;

        while(l<=u) {
            int mid = l + (u-l)/2;
            cout<<mid<<endl;

            if (nums[mid]==target) {
                return mid;
            } else if (nums[mid] > nums[u]) {
                // Mid on the left side
                if (target > nums[mid]) {
                    l = mid + 1;
                } else if (target >= nums[l]) {
                    u = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                cout<<"Here";
                // Mid on the right side
                if (target < nums[mid]) {
                    u = mid - 1;
                } else if (target <= nums[u]) {
                    cout<<"Here2";
                    l = mid + 1;
                } else {
                    u = mid - 1;
                }
            }
        }

        return -1;
    }
};
