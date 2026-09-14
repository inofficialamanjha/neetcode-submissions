class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            if (a[0]==b[0]) {
                return a[1] < b[1];
            } else {
                return a[0] < b[0];
            }
        });

        vector<vector<int>> mergedIntervals;
        mergedIntervals.push_back(intervals[0]);

        for(int i=1; i<intervals.size(); i++) {
            if (intervals[i][0] > mergedIntervals[mergedIntervals.size()-1][1]) {
                // Merge not possible
                mergedIntervals.push_back(intervals[i]);
            } else if (intervals[i][1] > mergedIntervals[mergedIntervals.size()-1][1]) {
                // It starts on before the end of the previous interval
                mergedIntervals[mergedIntervals.size()-1][1] = intervals[i][1];
            }
        }

        return mergedIntervals;
    }
};
