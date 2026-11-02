class MyCircularQueue {
    int front = -1;
    int rear = -1;
    vector<int> q;

public:
    MyCircularQueue(int k) {
        q = vector<int>(k, 0);
    }
    
    bool enQueue(int value) {
        int ans = false;
        if (isEmpty()) {
            front = rear = 0;
            q[rear] = value;
            ans = true;
        } else if (isFull()) {
            ans = false;
        } else {
            rear++;
            rear = rear % ((int)q.size());
            q[rear] = value;
            ans = true;
        }

        cout<<front<<" "<<rear<<" Enqueue: "<<ans<<endl;

        return ans;
    }
    
    bool deQueue() {
        bool ans = false;
        if (isEmpty()) {
            ans = false;
        } else if (front == rear) {
            front = rear = -1;
            ans = true;
        } else {
            front++;
            front = front % ((int)q.size());
            ans = true;
        }

        cout<<front<<" "<<rear<<" Dequeue: "<<ans<<endl;

        return ans;
    }
    
    int Front() {
        if (front!=-1) {
            return q[front];
        }

        return -1;
    }
    
    int Rear() {
        if (rear!=-1) {
            return q[rear];
        }

        return -1;
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return getSize() == q.size();
    }

    int getSize() {
        if (isEmpty()) {
            return 0;
        }

        if (rear >= front) {
            return rear - front + 1;
        } else {
            return (rear + 1) + (q.size() - front);
        }
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */