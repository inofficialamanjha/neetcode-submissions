class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> maxHeap;

        for(auto stone: stones) {
            maxHeap.push(stone);
        }

        while(maxHeap.size()>1) {
            int top1 = maxHeap.top();
            maxHeap.pop();
            int top2 = maxHeap.top();
            maxHeap.pop();

            if (top1!=top2) {
                maxHeap.push(top1-top2);
            } 
        }

        if (maxHeap.empty()) {
            return 0;
        } else {
            return maxHeap.top();
        }
    }
};
