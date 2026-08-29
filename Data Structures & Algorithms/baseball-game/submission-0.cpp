class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stk;

        for(auto& str: operations) {
            if (str == "C") {
                stk.pop();
            } else if (str == "D") {
                stk.push(2*stk.top());
            } else if (str == "+") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.push(a);
                stk.push(a+b);
            } else {
                stk.push(stoi(str));
            }
        }

        int sum = 0;
        while(!stk.empty()) {
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
};