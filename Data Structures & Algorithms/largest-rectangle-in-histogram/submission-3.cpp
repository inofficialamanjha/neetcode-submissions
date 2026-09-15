class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largestArea = 0;
        stack<int> stk;
        int size = heights.size();

        for(int i=0; i<size; i++) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                int currentTopIndex = stk.top();
                stk.pop();
                int startIndex = stk.empty() ? -1 : stk.top();
                int range = i - startIndex - 1;
                int area = heights[currentTopIndex] * range;
                // cout<<currentTopIndex<<" "<<area<<"Here1"<<endl;
                largestArea = max(largestArea, area);
            }

            stk.push(i);
        }

        int lastIndex = stk.empty() ? -1 : stk.top();
        while(!stk.empty()) {
            int currentTopIndex = stk.top();
            stk.pop();
            int startIndex = stk.empty() ? -1 : stk.top();
            int range = lastIndex - startIndex;
            int area = heights[currentTopIndex] * range;
            // cout<<currentTopIndex<<" "<<area<<"Here2"<<endl;
            largestArea = max(largestArea, area);
        }

        return largestArea;
    }
};
