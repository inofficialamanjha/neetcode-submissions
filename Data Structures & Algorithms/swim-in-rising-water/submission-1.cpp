class Solution {
public:
    int directions[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> time(n, vector<int>(n, INT_MAX));
        time[0][0] = grid[0][0];

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {
            auto [t, i, j] = pq.top();
            pq.pop();

            if (t > time[i][j]) {
                continue;
            }

            for (auto& direction : directions) {
                int next_i = i + direction[0];
                int next_j = j + direction[1];

                // Check validity
                if (next_i >= 0 && next_i < n &&
                    next_j >= 0 && next_j < n) {

                    // Time needed to enter the next cell
                    int newTime = max(t, grid[next_i][next_j]);

                    if (newTime < time[next_i][next_j]) {
                        time[next_i][next_j] = newTime;
                        pq.push({newTime, next_i, next_j});
                    }
                }
            }
        }

        return time[n - 1][n - 1];
    }
};