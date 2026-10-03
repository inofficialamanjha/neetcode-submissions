class Solution {
public:
    unordered_map<string, vector<string>> adj;
    unordered_set<string> visited;

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        // endWord must exist
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }

        // Build graph
        for (int i = 0; i < wordList.size(); i++) {

            if (checkDifference(wordList[i], beginWord)) {
                adj[beginWord].push_back(wordList[i]);
                adj[wordList[i]].push_back(beginWord);
            }

            for (int j = i + 1; j < wordList.size(); j++) {

                if (checkDifference(wordList[i], wordList[j])) {
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        // BFS
        queue<string> bfs;
        bfs.push(beginWord);
        visited.insert(beginWord);

        int transformation = 1;

        while (!bfs.empty()) {

            int currentQueueSize = bfs.size();

            for (int i = 0; i < currentQueueSize; i++) {

                string wordFront = bfs.front();
                bfs.pop();

                if (wordFront == endWord) {
                    return transformation;
                }

                for (auto& word : adj[wordFront]) {

                    if (!visited.count(word)) {
                        visited.insert(word);
                        bfs.push(word);
                    }
                }
            }

            transformation++;
        }

        return 0;
    }

    bool checkDifference(const string& word1, const string& word2) {

        int differences = 0;

        for (int i = 0; i < word1.length(); i++) {

            if (word1[i] != word2[i]) {
                differences++;

                if (differences > 1) {
                    return false;
                }
            }
        }

        return differences == 1;
    }
};