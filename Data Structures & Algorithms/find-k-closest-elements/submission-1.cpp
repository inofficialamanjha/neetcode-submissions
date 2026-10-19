class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int right = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = right - 1;

        vector<int> ans;

        while (k--) {
            if (left < 0) {
                ans.push_back(arr[right++]);
            }
            else if (right >= arr.size()) {
                ans.push_back(arr[left--]);
            }
            else {
                int leftDiff = abs(arr[left] - x);
                int rightDiff = abs(arr[right] - x);

                if (leftDiff <= rightDiff) {
                    ans.push_back(arr[left--]);
                }
                else {
                    ans.push_back(arr[right++]);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};