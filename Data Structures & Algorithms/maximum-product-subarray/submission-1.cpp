class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int globalMax = nums[0];
        int currentMax = nums[0];
        int currentMin = nums[0];

        for(int i=1; i<nums.size(); i++) {
            int mul1 = currentMax * nums[i];
            int mul2 = currentMin * nums[i];

            currentMax = nums[i];
            currentMin = nums[i];
            
            currentMax = max(currentMax, mul1);
            currentMax = max(currentMax, mul2);

            currentMin = min(currentMin, mul1);
            currentMin = min(currentMin, mul2);

            if (currentMax > globalMax) {
                globalMax = currentMax;
            }

            // cout<<currentMax<<" "<<currentMin<<" "<<globalMax<<endl;
        }

        return globalMax;
    }
};

/**

**/
