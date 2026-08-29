class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
    }

    void push(int x) {
        if (!q1.empty()) {
            q2.push(x);

            while (!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }

            swap(q1, q2);
        } 
        else {
            q1.push(x);
        }
    }

    int pop() {
        int x = q1.front();
        q1.pop();
        return x;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};