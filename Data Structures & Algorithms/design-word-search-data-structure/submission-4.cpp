class WordDictionary {
public:
    class TrieNode {
    public:
        char val;
        bool isEnd;
        vector<TrieNode*> next;

        TrieNode() {
            val = '\0';
            isEnd = false;
            next.resize(26, nullptr);
        }

        TrieNode(char val) {
            this->val = val;
            isEnd = false;
            next.resize(26, nullptr);
        }
    };

    TrieNode* head;

    WordDictionary() {
        head = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* current = head;

        for (int i = 0; i < word.size(); i++) {
            int pos = word[i] - 'a';

            if (current->next[pos] == nullptr) {
                current->next[pos] = new TrieNode(word[i]);
            }

            current = current->next[pos];
        }

        current->isEnd = true;
    }

    bool search(string word) {
        return searchRecursive(word, 0, head);
    }

    bool searchRecursive(const string& word, int pos, TrieNode* node) {

        // No valid Trie path
        if (node == nullptr) {
            return false;
        }

        // Reached the end of the search word
        if (pos == word.size()) {
            return node->isEnd;
        }

        char letter = word[pos];

        // Wildcard '.'
        if (letter == '.') {

            // Try all possible characters
            for (int i = 0; i < 26; i++) {

                if (node->next[i] != nullptr &&
                    searchRecursive(
                        word,
                        pos + 1,
                        node->next[i]
                    )) {
                    return true;
                }
            }

            return false;
        }

        // Normal character
        int index = letter - 'a';

        if (node->next[index] == nullptr) {
            return false;
        }

        return searchRecursive(
            word,
            pos + 1,
            node->next[index]
        );
    }
};