class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if (board[i][j]==word[0]) {
                    // Staring index
                    if (existFun(board, word, i, j)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }

    bool existFun(vector<vector<char>>& board, string word, int i=0, int j=0, int wordIndex=0) {
        if (wordIndex==word.size()) {
            return true;
        }

        int m = board.size();
        int n = board[0].size();

        if (i<0 || i>=m || j<0 || j>=n) {
            return false;
        }

        if (board[i][j]==word[wordIndex]) {
            // Check the next words
            board[i][j] = '\0'; // Special Character

            bool returnCheck = 
                existFun(board, word, i-1, j, wordIndex + 1) ||
                existFun(board, word, i, j+1, wordIndex + 1) ||
                existFun(board, word, i+1, j, wordIndex + 1) ||
                existFun(board, word, i, j-1, wordIndex + 1);

            board[i][j] = word[wordIndex]; // Backtracking

            return returnCheck;
        } else {
            return false;
        }
    };
};
