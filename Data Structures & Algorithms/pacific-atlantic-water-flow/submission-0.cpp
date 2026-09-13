class Solution {
public:
    int m, n;

    vector<vector<int>> directions = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    void dfs(vector<vector<int>>& heights,
             vector<vector<bool>>& visited,
             int i,
             int j) {

        visited[i][j] = true;

        for (auto& dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            if (ni < 0 || ni >= m || nj < 0 || nj >= n)
                continue;

            if (visited[ni][nj])
                continue;

            if (heights[ni][nj] < heights[i][j])
                continue;

            dfs(heights, visited, ni, nj);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific: top row + left column
        for (int j = 0; j < n; j++)
            dfs(heights, pacific, 0, j);

        for (int i = 0; i < m; i++)
            dfs(heights, pacific, i, 0);

        // Atlantic: bottom row + right column
        for (int j = 0; j < n; j++)
            dfs(heights, atlantic, m - 1, j);

        for (int i = 0; i < m; i++)
            dfs(heights, atlantic, i, n - 1);

        // Cells reachable from both oceans
        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};