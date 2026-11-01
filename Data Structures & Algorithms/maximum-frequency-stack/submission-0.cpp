class FreqStack {
    unordered_map<int, pair<int, list<int>>> freqMap;
    set<tuple<int, int, int>, greater<tuple<int, int, int>>> freqSet;
    int time = 0;

public:
    FreqStack() {
     ; // Do nothing   
    }
    
    void push(int val) {
        if (freqMap.count(val)) {
            // Remove from the set first
            freqSet.erase({freqMap[val].first, freqMap[val].second.front(), val});

            // Insert new one
            freqSet.insert({freqMap[val].first + 1, time, val});

            // Update map
            freqMap[val].first = freqMap[val].first + 1;
            freqMap[val].second.push_front(time);
        } else {
            list<int> lst;
            lst.push_front(time);
            freqMap[val] = {1, lst};
            freqSet.insert({freqMap[val].first, time, val});
        }
        
        time++;
    }
    
    int pop() {
      if (freqMap.size()==0) {
        return -1;
      }

      auto [f, t, v] = *freqSet.begin();

      // Update the elements
      freqSet.erase(freqSet.begin());
      freqMap[v].second.pop_front();
      freqMap[v].first--;

      if (freqMap[v].first==0) {
        // The element has gone
        freqMap.erase(v);
      } else {
        // Take the last time
        freqSet.insert({freqMap[v].first, *(freqMap[v].second.begin()),v});
      }

      return v;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */