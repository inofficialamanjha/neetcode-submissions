class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedStr = "";

        for(auto str: strs) {
            encodedStr += to_string(str.size()) + '#' + str;
        }

        return encodedStr;
    }

    vector<string> decode(string s) {
        if (s == "") {
            return {};
        }

        vector<string> ans;

        string strSize = "";
        for(int i=0; i<s.size(); i++)
        {
            if (s[i] !='#') {
                strSize += s[i]; // Reconstructing the number
            } else {
                // Found '#'
                int finalSize = stoi(strSize);

                string _ans = "";
                
                for(int k=0; k<finalSize; k++) {
                    _ans += s[k + i + 1];
                }

                ans.push_back(_ans);

                i = i + finalSize;
                strSize = "";
            }
        }

        return ans;
    }
};
