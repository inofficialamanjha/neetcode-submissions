class MinStack {
public:
    stack<pair<int, int>> stk;

    MinStack() {
        ; // Do nothing
    }
    
    void push(int val) {
        if (stk.empty()) {
            stk.push({val, val});
        } else {
            auto [top, topMin] = stk.top();
            stk.push({val, min(val, topMin)});
        }
    }
    
    void pop() {
        if (stk.empty()) {
            return;
        }

        stk.pop(); 
    }
    
    int top() {
        if (stk.empty()) {
            return -1;
        }

        return stk.top().first;
    }
    
    int getMin() {
        if (stk.empty()) {
            return -1;
        }

        return stk.top().second;
    }
};
