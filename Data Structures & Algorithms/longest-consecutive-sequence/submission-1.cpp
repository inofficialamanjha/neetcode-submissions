class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numbers(nums.begin(), nums.end());

        int longest = 0;

        for (int num : numbers) {
            // Only start counting if this is the beginning
            // of a sequence.
            if (!numbers.contains(num - 1)) {
                int current = num;
                int length = 1;

                while (numbers.contains(current + 1)) {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};