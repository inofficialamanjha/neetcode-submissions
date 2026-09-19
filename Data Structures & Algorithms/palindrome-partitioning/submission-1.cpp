class Solution {
public:
    vector<vector<string>> ans;
    vector<string> curr;
    vector<vector<bool>> dp;

    vector<vector<string>> partition(string s) {
        int n = s.size();

        dp = vector<vector<bool>>(n, vector<bool>(n, false));

        for(int k=0; k<n; k++) {
            for (int i=0; i+k<n; i++) {
                if (k<2) {
                    dp[i][i+k] = (s[i] == s[i+k]);
                } else {
                    dp[i][i+k] = (s[i]==s[i+k]) && dp[i+1][i+k-1];
                }
                // cout<<i<<" "<<i+k<<" "<<dp[i][i+k]<<endl;
            }
        }

        generate(s);
        return ans;
    }

    void generate(string& s, int current=0) {
        if (current==s.size()) {
            ans.push_back(curr);
            return;
        }

        for(int j=current; j<s.size(); j++) {
            if (dp[current][j]) {

                // Possible palindrome - push to the string
                string temp = s.substr(current, j - current + 1);

                curr.push_back(temp); // Move forward
                generate(s, j+1);
                curr.pop_back(); // Move backward
            }
        }
    }
};

/**
p(i,j) is a palindrome if s[i]==s[j] and p(i+1, j-1) is true

(0,0), (1,1), (2,2), (3,3)
(0,1), (1,2), (2,3)
(0,2), (1,3)
(0,3)
**/
