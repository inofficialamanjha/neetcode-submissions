
class Solution {
public:
    vector<vector<int>> memo;

    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();

        if (s3.length() != m + n) {
            return false;
        }

        memo.assign(m + 1, vector<int>(n + 1, -1));

        return func(s1, s2, s3, 0, 0);
    }

    bool func(string& s1, string& s2, string& s3, int i, int j) {
        if (i == s1.length() && j == s2.length()) {
            return true;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int k = i + j;
        bool val = false;

        if (i < s1.length() && s1[i] == s3[k]) {
            val = func(s1, s2, s3, i + 1, j);
        }

        if (!val && j < s2.length() && s2[j] == s3[k]) {
            val = func(s1, s2, s3, i, j + 1);
        }

        return memo[i][j] = val;
    }
};
