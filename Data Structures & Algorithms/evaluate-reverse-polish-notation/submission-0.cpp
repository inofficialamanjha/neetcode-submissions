class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for(int i=0; i<tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int top1 = stk.top();
                stk.pop();
                int top2 = stk.top();
                stk.pop();
                
                if (tokens[i] == "+") {
                    stk.push(top2 + top1);
                } else if (tokens[i] == "*") {
                    stk.push(top2*top1);
                } else if (tokens[i]=="-") {
                    stk.push(top2-top1);
                } else {
                    stk.push(top2/top1);
                }
            } else {
                stk.push(stoi(tokens[i]));
            }
        }

        return stk.top();
    }
};
