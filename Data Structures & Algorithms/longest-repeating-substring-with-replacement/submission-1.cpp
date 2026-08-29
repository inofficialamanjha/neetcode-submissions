class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        for(int i = 0; i<26; i++) {
            ans = max(ans, slidingWindow(s, k, 'A' + i));
        }
        return ans;
    }

    int slidingWindow(string s, int k, char c) {
        int replacements = 0;
        queue<int> window;
        int ans = 0;

        for(int i=0; i<s.size(); i++) {
            if (s[i] == c) {
                window.push(s[i]);
            } else {
                // s[i] is not the same
                if (replacements == k) {
                    // Out of replacements - we will push flush uptil the last replacement
                    while(!window.empty() && window.front()==c) {
                        window.pop();
                    }

                    // Reached where the replacement happens
                    window.pop();
                    window.push(s[i]);
                } else {
                    // less replacements
                    window.push(s[i]);
                    replacements++;
                }
            }

            ans = max(ans, (int)window.size());
        }

        return ans;
    }
};
