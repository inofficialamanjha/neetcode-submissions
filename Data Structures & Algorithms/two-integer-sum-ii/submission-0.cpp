class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;

        while(i<j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                return {i+1, j+1};
            } else if (sum <= target) {
                // We increase the sum
                i++;
            } else {
                // We decrease the sum
                j--;
            }
        }

        return {0,0};
    }
};
