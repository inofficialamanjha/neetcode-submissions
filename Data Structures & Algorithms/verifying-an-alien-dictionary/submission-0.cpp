class Solution {
public:
    vector<int> priority;

    Solution() {
        priority = vector<int>(26, 0);
    }

    bool isAlienSorted(vector<string>& words, string order) {
        vector<string> wordsCopy = words;

        for (int i = 0; i < 26; i++) {
            priority[order[i] - 'a'] = i;
        }

        sort(wordsCopy.begin(), wordsCopy.end(),
            [this](const string& a, const string& b) {
                for (int i = 0; i < a.size() || i < b.size(); i++) {
                    if (i == a.size()) {
                        return true;  // Shorter word comes first
                    } else if (i == b.size()) {
                        return false;
                    } else {
                        int pA = priority[a[i] - 'a'];
                        int pB = priority[b[i] - 'a'];

                        if (pA != pB) {
                            return pA < pB;
                        }
                    }
                }

                return false; // Equal words
            }
        );

        for (int i = 0; i < words.size(); i++) {
            if (words[i] != wordsCopy[i]) {
                return false;
            }
        }

        return true;
    }
};