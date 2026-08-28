class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }

        int last = 0;

        for (int i = 0; i <= x / 2; i++) {
            long long square = 1LL * i * i;

            if (square == x) {
                return i;
            }
            else if (square < x) {
                last = i;
            }
            else {
                break;
            }
        }

        return last;
    }
};