class Solution {
public:
    unordered_map<int, unordered_map<int, bool>> mp;

    bool isInterleave(string s1, string s2, string s3) {
       if (s3.length() != s1.length() + s2.length()) {
            return false;
       }

       return func(s1, s2, s3);
    }

    bool func(string& s1, string& s2, string& s3, int i = 0, int j = 0) {
        if (i+j==s3.length()) {
            return true;
        }

        if (mp.count(i)) {
            if (mp[i].count(j)) {
                return mp[i][j];
            }
        }

        bool val = false;

        if (i<s1.length() && s3[i+j]==s1[i]) {
            val = val || func(s1, s2, s3, i+1, j);
        }

        if (s2.length() && s3[i+j]==s2[j]) {
            val = val || func(s1, s2, s3, i, j+1);
        }

        mp[i][j] = val;
        return val;
    }
};
