class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMax(height.size(),0);
        vector<int> rightMax(height.size(),0);

        // Calculating left Max
        leftMax[0] = height[0];
        for(int i=1; i<height.size(); i++) {
            leftMax[i] = max(leftMax[i-1], height[i]);
        }

        rightMax[height.size()-1] = height[height.size()-1];
        for(int i=height.size()-2; i>=0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }

        int tr = 0;
        for(int i=0; i<height.size(); i++) {
            int minBound = min(leftMax[i], rightMax[i]);
            if(minBound>height[i])
                tr+=minBound-height[i];
        }
        return tr;
    }
};
