class Solution {
public:
    int directions[4][2] = {{1,0}, {-1, 0}, {0, -1}, {0, 1}};

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int, int>> bfs;

        for(int i=0; i<m; i++) {
            if (board[i][0]=='O') {
                board[i][0] = 'A';
                bfs.push({i,0});
            }

            if (board[i][n-1]=='O') {
                board[i][n-1] = 'A';
                bfs.push({i, n-1});
            }
        }

        for(int j=0; j<n; j++) {
            if (board[0][j]=='O') {
                board[0][j] = 'A';
                bfs.push({0, j});
            }

            if (board[m-1][j]=='O') {
                board[m-1][j] = 'A';
                bfs.push({m-1, j});
            }
        }

        while(!bfs.empty()) {
            auto& [i, j] = bfs.front();
            bfs.pop();

            for(auto& direction: directions) {
                int newI = i + direction[0];
                int newJ = j + direction[1];

                if (newI>=0 && newI<m && newJ>=0 && newJ<n) {
                    if (board[newI][newJ]=='O') {
                        board[newI][newJ] = 'A'; // Marked impossible to surround
                        bfs.push({newI, newJ});
                    }
                }
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if (board[i][j]=='O') {
                    board[i][j] = 'X';
                } else if (board[i][j]=='A') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
