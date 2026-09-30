class Solution {
public:
    unordered_map<int, unordered_map<int, int>> memo;

    int minDistance(string word1, string word2, int i = 0, int j = 0) {
        if (memo.count(i)) {
            if (memo[i].count(j)) {
                return memo[i][j];
            }
        }

        if (i == word1.length() || j == word2.length()) {
            memo[i][j] = word1.length() - i + word2.length() - j;
            return memo[i][j];
        }

        if (word1[i] == word2[j]) {
            memo[i][j] = minDistance(word1, word2, i + 1, j + 1);
            return memo[i][j];
        }

        int insert = minDistance(word1, word2, i, j + 1);
        int remove = minDistance(word1, word2, i + 1, j);
        int replace = minDistance(word1, word2, i + 1, j + 1);

        memo[i][j] = 1 + min({insert, remove, replace});
        return memo[i][j];
    }
};