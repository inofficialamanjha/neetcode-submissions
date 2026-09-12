class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = 0;
        for(auto& n: nums) {
            num = num^n;
        }
        return num;
    }
};
