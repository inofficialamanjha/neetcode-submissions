class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        bool isZero = false;
        for(int i=0; i<nums.size(); i++) {
            if (nums[i] == 0) {
                if (isZero == true) {
                    product *= 0; // If it occurs twice - the product is zero
                } else {
                    isZero = true; // If it occurs once - there is only one zero
                }
            } else {
                product *= nums[i];
            }
        }

        vector<int> output;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0) {
                output.push_back(product);
            } else {
                if (isZero) {
                    output.push_back(0);
                } else {
                    output.push_back(product / nums[i]);
                }
            }
        }

        return output;
    }
};
