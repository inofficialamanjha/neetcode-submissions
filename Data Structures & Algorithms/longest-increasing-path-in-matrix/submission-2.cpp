
class Solution {
public:
    vector<vector<int>> maxPath;
    int directions[4][2] = {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}
    };

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;

        int n = matrix[0].size();
        if (n == 0) return 0;

        maxPath = vector<vector<int>>(m, vector<int>(n, 0));

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, func(matrix, i, j));
            }
        }

        return ans;
    }

    int func(vector<vector<int>>& matrix, int i, int j) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (maxPath[i][j] != 0) {
            return maxPath[i][j];
        }

        int ans = 1;

        for (auto& direction : directions) {
            int new_i = i + direction[0];
            int new_j = j + direction[1];

            if (new_i < 0 || new_i >= m ||
                new_j < 0 || new_j >= n) {
                continue;
            }

            if (matrix[new_i][new_j] > matrix[i][j]) {
                ans = max(ans, 1 + func(matrix, new_i, new_j));
            }
        }

        maxPath[i][j] = ans;
        return ans;
    }
};
