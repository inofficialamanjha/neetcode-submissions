class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }

        // ASCII characters
        vector<int> freq(128, 0);

        for (char ch : t) {
            freq[ch]++;
        }

        int left = 0;
        int required = t.size();

        int minLength = INT_MAX;
        int minStart = 0;

        for (int right = 0; right < s.size(); right++) {
            char ch = s[right];

            // This character was still needed
            if (freq[ch] > 0) {
                required--;
            }

            freq[ch]--;

            // Window contains all characters of t
            while (required == 0) {

                int currLength = right - left + 1;

                if (currLength < minLength) {
                    minLength = currLength;
                    minStart = left;
                }

                char leftChar = s[left];

                freq[leftChar]++;

                // Removing this character breaks the window
                if (freq[leftChar] > 0) {
                    required++;
                }

                left++;
            }
        }

        return minLength == INT_MAX
            ? ""
            : s.substr(minStart, minLength);
    }
};