class Solution {
public:
    int directions[4][2] = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1}
    };

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, bfs(i, j, grid));
                }
            }
        }

        return maxArea;
    }

    int bfs(int i, int j, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> search;

        search.push({i, j});
        grid[i][j] = 0;  // Mark visited when adding to queue

        int area = 0;

        while (!search.empty()) {
            auto current = search.front();
            search.pop();

            area++;

            for (auto& direction : directions) {
                int next_i = current.first + direction[0];
                int next_j = current.second + direction[1];

                if (next_i >= 0 && next_i < m &&
                    next_j >= 0 && next_j < n &&
                    grid[next_i][next_j] == 1) {

                    grid[next_i][next_j] = 0;  // Mark immediately
                    search.push({next_i, next_j});
                }
            }
        }

        return area;
    }
};