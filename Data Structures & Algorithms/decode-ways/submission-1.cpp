class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();

        vector<int> dp(size + 1, 0);

        // Empty suffix has one valid decoding
        dp[size] = 1;

        for (int i = size - 1; i >= 0; i--) {

            // '0' cannot be decoded by itself
            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }

            // Take current digit alone
            dp[i] = dp[i + 1];

            // Try taking current digit + next digit
            if (i + 1 < size) {

                int number = (s[i] - '0') * 10
                           + (s[i + 1] - '0');

                // Valid mappings are 10 -> 26
                if (number >= 10 && number <= 26) {
                    dp[i] += dp[i + 2];
                }
            }
        }

        return dp[0];
    }
};