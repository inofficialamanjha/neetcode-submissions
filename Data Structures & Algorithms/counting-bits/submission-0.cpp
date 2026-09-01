class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,-1);
        for(int i=0; i<=n; i++) {
            ans[i] = calculate(i); 
        }
        return ans;
    }

    int calculate(int n) {
        int count = 0;
        while(n!=0) {
            if(n&1 == 1) {
                count++;
            }
            n = n >> 1;
        }
        return count;
    }
};
