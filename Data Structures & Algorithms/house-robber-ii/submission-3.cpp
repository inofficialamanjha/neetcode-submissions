class Solution {
public:
    unordered_map<int, unordered_map<int, int>> memo;

    int rob(vector<int>& nums) {
        if (nums.size()==1) {
            return nums[0];
        }

        int maxGlobal = nums[0];
        for(int i=0; i<nums.size(); i++) {
            maxGlobal = max(maxGlobal, dfs(nums, i+2, i) + nums[i]);
        }
        return maxGlobal;
    }

    int dfs(vector<int>& nums, int current, int lowerBound) {
        int n = nums.size();
        int currentNext = (current+1)%n;
        current = current%n;



        if(memo.count(current)) {
            if (memo[current].count(lowerBound)) {
                return memo[current][lowerBound];
            }
        }


        if(current==lowerBound || currentNext==lowerBound) {
            return 0;
        }

        int takeIt = dfs(nums, current+2, lowerBound) + nums[current];
        int ignore = dfs(nums, current+1, lowerBound);
        // cout<<current<<", "<<lowerBound<<", "<<takeIt<<", "<<ignore<<endl;
        int ans = max(takeIt, ignore);
        memo[current][lowerBound] = ans;
        return ans;
    }
};
