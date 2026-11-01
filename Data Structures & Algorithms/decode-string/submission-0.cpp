class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;

        int i = 0;

        for(int i=0; i<s.size(); i++) {
            char ch = s[i];

            if (ch == '[') {
                stk.push(ch);
            } else if (ch == ']') {
                vector<char> res;

                while(stk.top()!='[') {
                    char _ch = stk.top();
                    stk.pop();
                    res.push_back(_ch);
                }

                reverse(res.begin(), res.end());

                stk.pop(); // Removing '['

                // Now determining the number
                string num = "";
                while(!stk.empty() && isdigit(stk.top())) {
                    num = stk.top() + num;
                    stk.pop();
                }

                int n = stoi(num);

                // Insert them again to the stack
                for(int j=0; j<n; j++) {
                    for(auto __ch: res) {
                        stk.push(__ch);
                    }
                }

            } else if (isdigit(ch)) {
                stk.push(ch);
            } else {
                stk.push(ch);
            }
        }

        string ans = "";
        while(!stk.empty()) {
            ans = stk.top() + ans; // Stk.top() comes before the ans
            stk.pop();
        }
        return ans;
    }
};