class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<char>> board;

    vector<vector<string>> solveNQueens(int n) {
        for(int i=0; i<n; i++) {
            vector<char> row;
            for(int j=0; j<n; j++) {
                row.push_back('.');   
            }
            board.push_back(row);
        }

        generate(n);
        return ans;  
    }

    void generate(int size, int i=0) {
        if (i==size) {
            addToAns(size);
            return;
        }

        for(int j=0; j<size; j++) {
            if (check(i,j,size)) {
                board[i][j] = 'Q'; // Make it a queen
                generate(size, i+1); // Generate next set
                board[i][j] = '.'; // Backtrack
            }
        }
    }

    void addToAns(int size) {
        vector<string> temp;

        for(int i=0; i<size; i++) {
            string _temp = "";
            for(int j=0; j<size; j++) {
                _temp += board[i][j];
            }
            temp.push_back(_temp);
        }

        ans.push_back(temp);
    }

bool check(int m, int n, int size) {
    if (board[m][n] == 'Q') {
        return false;
    }

    // Check column
    for (int i = 0; i < m; i++) {
        if (board[i][n] == 'Q') {
            return false;
        }
    }

    // Check diagonals
    int k = 1;

    while (m-k >= 0 || n-k >= 0 || n+k < size) {

        // ↖
        if (m-k >= 0 && n-k >= 0) {
            if (board[m-k][n-k] == 'Q') {
                return false;
            }
        }

        // ↗
        if (m-k >= 0 && n+k < size) {
            if (board[m-k][n+k] == 'Q') {
                return false;
            }
        }

        k++;
    }

    return true;
}
};
