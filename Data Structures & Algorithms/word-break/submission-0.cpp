class Solution {
public:
    unordered_map<int,bool> mp;
    bool wordBreak(string s, vector<string>& wordDict, int current=0) {
        if (current==s.size()) {
            return true;
        }

        if (mp.count(current)) {
            return mp[current];
        }

        for(int i=0; i<wordDict.size(); i++) {
            if (isPrefix(s, current, wordDict[i])) {
                // cout<<s.substr(current, wordDict[i].size())<<endl;
                if (wordBreak(s, wordDict, current+wordDict[i].size())) {
                    mp[current] = true;
                    return true;
                }
            }
        }

        mp[current] = false;
        return false;
    }

    bool isPrefix(string& s, int current, string& word) {
        for(int i=0; i<word.size(); i++) {
            if (current+i>s.size() || word[i]!=s[current+i]) {
                return false;
            }
        }

        return true;
    }
};
