class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        if (k == 0)
            return;

        int cycles = gcd(n, k);

        for (int i = 0; i < cycles; i++) {

            int currIndex = i;
            int current = nums[currIndex];

            do {
                int nextIndex = (currIndex + k) % n;

                int temp = nums[nextIndex];
                nums[nextIndex] = current;
                current = temp;

                currIndex = nextIndex;

            } while (currIndex != i);
        }
    }
};