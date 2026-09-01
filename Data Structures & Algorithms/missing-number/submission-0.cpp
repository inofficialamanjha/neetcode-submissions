class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
            sum += nums[i];
        
        int expectedSum = (nums.size() * (nums.size() + 1))/2;

        int delta = expectedSum - sum;

        return delta;
    }
};
