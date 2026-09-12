#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    struct TrieNode {
        vector<TrieNode*> next;
        string word;

        TrieNode() {
            next.resize(26, nullptr);
            word = "";
        }
    };

    TrieNode* root;
    vector<string> ans;

    int m, n;

    vector<vector<int>> directions = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    void insert(const string& word) {
        TrieNode* current = root;

        for (char c : word) {
            int pos = c - 'a';

            if (current->next[pos] == nullptr) {
                current->next[pos] = new TrieNode();
            }

            current = current->next[pos];
        }

        current->word = word;
    }

    void dfs(vector<vector<char>>& board,
             int i,
             int j,
             TrieNode* current) {

        // Outside board
        if (i < 0 || i >= m ||
            j < 0 || j >= n) {
            return;
        }

        // Already visited
        if (board[i][j] == '#') {
            return;
        }

        char c = board[i][j];
        int pos = c - 'a';

        // No word has this prefix
        if (current->next[pos] == nullptr) {
            return;
        }

        TrieNode* nextNode = current->next[pos];

        // Found a complete word
        if (!nextNode->word.empty()) {
            ans.push_back(nextNode->word);

            // Avoid duplicate result
            nextNode->word = "";
        }

        // Mark cell as visited
        board[i][j] = '#';

        // Explore four directions
        for (auto& direction : directions) {
            int newI = i + direction[0];
            int newJ = j + direction[1];

            dfs(board, newI, newJ, nextNode);
        }

        // Backtrack
        board[i][j] = c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        m = board.size();
        n = board[0].size();

        root = new TrieNode();

        // Build Trie from words
        for (const string& word : words) {
            insert(word);
        }

        // DFS from every cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};