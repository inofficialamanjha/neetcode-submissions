class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;

        string current = "";
        int num = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }
            else if (ch == '[') {
                countStack.push(num);
                stringStack.push(current);

                num = 0;
                current = "";
            }
            else if (ch == ']') {
                int count = countStack.top();
                countStack.pop();

                string previous = stringStack.top();
                stringStack.pop();

                while (count--) {
                    previous += current;
                }

                current = previous;
            }
            else {
                current += ch;
            }
        }

        return current;
    }
};