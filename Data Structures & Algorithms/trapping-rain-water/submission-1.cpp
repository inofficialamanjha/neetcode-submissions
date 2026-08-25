class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int total = 0;

        for (int current = 0; current < height.size(); current++) {

            // Current bar can close a basin
            while (!stk.empty() &&
                   height[current] > height[stk.top()]) {

                // The bar being popped is the bottom
                int bottom = stk.top();
                stk.pop();

                // No left boundary
                if (stk.empty())
                    break;

                // New top is the left boundary
                int left = stk.top();

                // Current bar is the right boundary
                int right = current;

                int width = right - left - 1;

                int boundedHeight =
                    min(height[left], height[right])
                    - height[bottom];

                total += width * boundedHeight;
            }

            // Current bar waits for a future right boundary
            stk.push(current);
        }

        return total;
    }
};