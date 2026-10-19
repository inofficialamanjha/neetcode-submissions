class StockSpanner {
public:
    stack<pair<int, int>> stk;
    int date;

    StockSpanner() {
        date = 0;
    }
    
    int next(int price) {
        date++;

        while(!stk.empty()) {
            auto [val, topDate] = stk.top();

            if (val <= price) {
                // We can evict this
                stk.pop();
            } else {
                break;
            }
        }

        if (stk.empty()) {
            stk.push({price, date});
            return date;
        } else {
            auto [val, topDate] = stk.top();
            stk.push({price, date});
            return date - topDate;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */