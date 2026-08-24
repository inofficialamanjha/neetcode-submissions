class Solution {
public:
    int tribonacci(int n) {
        int tn_3 = 0;
        int tn_2 = 1;
        int tn_1 = 1;

        if (n == 0)
            return tn_3;

        if (n == 1 || n == 2)
            return tn_1;

        for (int i = 3; i <= n; i++) {
            int tn_i = tn_3 + tn_2 + tn_1;

            tn_3 = tn_2;
            tn_2 = tn_1;
            tn_1 = tn_i;
        }

        return tn_1;
    }
};