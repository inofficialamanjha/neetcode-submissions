class FreqStack {
    unordered_map<int, stack<int>> frequencyBucket;
    unordered_map<int, int> currentFrequency;
    int maxFrequency = 0;

public:
    FreqStack() {
        ;
    }
    
    void push(int val) {
        if (currentFrequency.count(val)) {
            currentFrequency[val]++;
            frequencyBucket[currentFrequency[val]].push(val);
        } else {
            currentFrequency[val] = 1;
            frequencyBucket[1].push(val);
        }

        maxFrequency = max(maxFrequency, currentFrequency[val]);
    }
    
    int pop() {
        if (maxFrequency==0) {
            return -1;
        }

        int val = frequencyBucket[maxFrequency].top();

        frequencyBucket[maxFrequency].pop();
        if (frequencyBucket[maxFrequency].empty()) {
            frequencyBucket.erase(maxFrequency);
            maxFrequency--;
        }

        currentFrequency[val]--;
        if (currentFrequency[val]==0) {
            currentFrequency.erase(val);
        }

        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */