class Solution {
public:
    int countSubstrings(string s) {
        int size = s.size();

        int counter = 0;
        vector<vector<bool>> dp(size, vector<bool>(size, false));

        for(int k=0; k<size; k++) {
            for(int i=0; i+k<size; i++) {
                int start = i;
                int end = i+k;

                if(k<2) {
                    dp[start][end] = s[start] == s[end];
                } else {
                    dp[start][end] = (s[start] == s[end]) && dp[start+1][end-1];
                }

                if (dp[start][end]) {
                    counter++;
                }
            }
        }

        return counter;
    }
};
