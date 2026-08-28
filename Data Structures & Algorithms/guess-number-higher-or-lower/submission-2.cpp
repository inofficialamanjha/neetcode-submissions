class Solution {
public:
    int guessNumber(int n, int s = 1) {
        int mid = s + (n - s) / 2;

        int g = guess(mid);

        if (g == 0) {
            return mid;
        }
        else if (g == 1) {
            // Picked number is higher
            return guessNumber(n, mid + 1);
        }
        else {
            // Picked number is lower
            return guessNumber(mid - 1, s);
        }
    }
};