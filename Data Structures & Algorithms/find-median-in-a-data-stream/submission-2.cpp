class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {
        ;
    }
    
    void addNum(int num) {
        if(maxHeap.empty()) {
            maxHeap.push(num);
        } else {
            // Both are non-empty right now - and also assume both are balanced
            if (num < maxHeap.top()) {
                maxHeap.push(num); // Push to the left
            } else {
                minHeap.push(num); // Push to right
            }

            // Let's balance them
            while(maxHeap.size()!=minHeap.size() && maxHeap.size()!=minHeap.size()+1) {
                if (maxHeap.size() > minHeap.size()) {
                    // transfer to minHeap
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                } else {
                    // transfer to maxHeap
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                }
            }
        }
    }
    
    double findMedian() {
        if(!maxHeap.empty()) {
           // cout<<maxHeap.top()<<" ";
        }

        if(!minHeap.empty()) {
          // cout<<minHeap.top()<<" ";
        }

        // cout<<endl;

        if (maxHeap.size()>minHeap.size()) {
            // Odd digits - maxHeap is always one above minHeap
            
            return maxHeap.top();
        } else {
            
            return (maxHeap.top() + minHeap.top())/2.0;
        }
    }
};
