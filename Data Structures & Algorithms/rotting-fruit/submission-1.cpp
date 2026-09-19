class Solution {
public:
    int directions[4][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> bfs;
        int fresh = 0;

        // Add all initially rotten oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    bfs.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        int minutes = 0;

        while (!bfs.empty() && fresh > 0) {
            int size = bfs.size();

            for (int i = 0; i < size; i++) {
                auto [x, y] = bfs.front();
                bfs.pop();

                for (auto& d : directions) {
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if (nx >= 0 && nx < m &&
                        ny >= 0 && ny < n &&
                        grid[nx][ny] == 1) {

                        grid[nx][ny] = 2;
                        fresh--;
                        bfs.push({nx, ny});
                    }
                }
            }

            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};