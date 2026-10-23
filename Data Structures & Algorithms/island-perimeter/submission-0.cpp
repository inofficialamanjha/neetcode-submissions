class Solution {
public:
    int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int perimeter = 0;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]==0) {
                    continue;
                }

                for(int k=0; k<4; k++) {
                    int next_i = i + directions[k][0];
                    int next_j = j + directions[k][1];

                    if (next_i < 0 || next_i >=m || next_j < 0 || next_j >= n) {
                        perimeter++;
                    } else {
                        if (grid[next_i][next_j]==0) {
                            perimeter++;
                        }
                    }
                }
            }
        }

        return perimeter;
    }
};