class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        bool found = false;
        int mi = INT_MAX;
        int sum = 0;
        queue<int> window;

        for(int i=0; i<nums.size(); i++) {
            while((sum + nums[i] > target) && !window.empty()) {
                // There's scope of reduction from sum - while adding the new element
                int f = window.front();

                if (sum - f + nums[i] < target) {
                    // Do nothing
                    break;
                } else {
                    window.pop();
                    sum -= f;
                }
            }

            window.push(nums[i]);
            sum += nums[i];

            cout<<i<<" "<<sum<<endl;

            if (sum >= target) {
                mi = min((int)window.size(), mi);
                found = true;
            }
        }

        if (found) {
            return mi;
        } else {
            return 0;
        }
    }
};