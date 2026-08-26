class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        queue<int> window;
        unordered_map<char,bool> present;
        int maxLength = 0;

        for(int i=0; i<s.size(); i++) {
            if (present.count(s[i]) && present[s[i]]==true) {
                while(window.front()!=s[i]) {
                    present[window.front()] = false;
                    window.pop();
                }
                present[s[i]] = false;
                window.pop();
            }
            
            window.push(s[i]);
            present[s[i]] = true;
            maxLength = max(maxLength, (int)window.size());
        }

        return maxLength;
    }
};
