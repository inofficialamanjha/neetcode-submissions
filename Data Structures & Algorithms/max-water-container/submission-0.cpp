class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int area = 0;

        while(left<right) {
            int length = min(heights[left], heights[right]);
            int breath = right - left;
            area = max(area, length*breath);

            if(heights[left]<heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return area;
    }
};
