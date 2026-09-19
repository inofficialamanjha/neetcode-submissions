class Solution {
public:
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        // All treasures are sources
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    q.push({i, j});
            }
        }

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (auto& d : dir) {
                int ni = i + d[0];
                int nj = j + d[1];

                if (ni < 0 || ni >= m || nj < 0 || nj >= n)
                    continue;

                if (grid[ni][nj] != INT_MAX)
                    continue;

                grid[ni][nj] = grid[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }
};