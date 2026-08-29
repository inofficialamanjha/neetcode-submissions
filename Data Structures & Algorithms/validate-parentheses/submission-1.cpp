class Solution {
public:
    string opening = "({[";
    string closing = ")}]";

    bool isValid(string s) {
        stack<char> stk;

        for (char bracket : s) {
            if (opening.find(bracket) != string::npos) {
                stk.push(bracket);
            } 
            else {
                if (stk.empty()) {
                    return false;
                }

                char o = stk.top();
                stk.pop();

                int index = closing.find(bracket);

                if (o != opening[index]) {
                    return false;
                }
            }
        }

        return stk.empty();
    }
};