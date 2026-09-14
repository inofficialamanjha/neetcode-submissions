class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size()==1) {
            return true;
        }

        int i = 0;

        while(i<=nums.size()) {
            int maxRange = 0;
            int range = i + nums[i];

            for(int j=i+1; j<=range; j++) {
                if (j==nums.size()-1) {
                    return true;
                }

                // Slect the one that gives maximum range - the range from j+nums[j]
                if (j + nums[j] >= maxRange) {
                    i = j;
                    maxRange = j + nums[j];
                }
            }

            if (maxRange==0) {
                return false;
            }
        }

        return true;
    }
};
