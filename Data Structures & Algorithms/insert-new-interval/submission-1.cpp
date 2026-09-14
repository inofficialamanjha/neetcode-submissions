class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int n = intervals.size();

        // Find insertion position
        int pos = 0;
        while (pos < n && intervals[pos][0] < newInterval[0])
            pos++;

        // Make space
        intervals.push_back({0, 0});
        for (int i = n; i > pos; i--)
            intervals[i] = intervals[i - 1];

        intervals[pos] = newInterval;

        // Merge in-place
        int write = 0;

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= intervals[write][1]) {
                intervals[write][1] =
                    max(intervals[write][1], intervals[i][1]);
            } else {
                intervals[++write] = intervals[i];
            }
        }

        intervals.resize(write + 1);

        return intervals;
    }
};