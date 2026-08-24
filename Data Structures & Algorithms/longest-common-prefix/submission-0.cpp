class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string f = strs[0];
        string lcp = "";

        for(int i=0; i<f.length(); i++) {
            char ch = f[i];

            for(int j=0; j<strs.size(); j++) {
                
                if (i<strs[j].size() && strs[j][i]==ch) {
                    ; // Do nothing
                } else {
                    return lcp;
                }
            }

            lcp += ch;
        }

        return lcp;
    }
};