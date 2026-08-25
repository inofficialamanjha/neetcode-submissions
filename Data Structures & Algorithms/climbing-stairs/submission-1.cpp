class Solution {
public:
    int climbStairs(int n) {
        int fn_2 = 1;
        int fn_1 = 2;

        if(n==1)
            return fn_2;
        if(n==2)
            return fn_1;

        int curr = -1;
        for(int i=3; i<=n; i++) {
            curr = fn_1 + fn_2;
            fn_2 = fn_1;
            fn_1 = curr;
        }

        return curr;
    }
};
