class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        string window = "";

        for (int i = 0; i < s2.size(); i++) {
            if (window.size() == s1.size()) {
                window = window.substr(1, s1.size() - 1);
            }

            window += s2[i];

            if (window.size() == s1.size() &&
                compareSignatures(s1, window)) {
                return true;
            }
        }

        return false;
    }

    bool compareSignatures(const string& s1, const string& s2) {
        vector<int> count(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }

        for (int num : count) {
            if (num != 0) {
                return false;
            }
        }

        return true;
    }
};