class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> _nums(2*nums.size(), 0);
        for(int i=0; i<nums.size(); i++) {
            _nums[i] = _nums[i+nums.size()] = nums[i];
        }
        return _nums;
    }
};