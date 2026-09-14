class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            if (a[0]==b[0]) {
                return a[1] < b[1];
            } else {
                return a[0] < b[0];
            }
        });

        for(int i=0; i<intervals.size(); i++) {
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
        }

        int endTime = intervals[0][1];
        int counter = 1;

        for(int i=1; i<intervals.size(); i++) {
            if (intervals[i][0] >= endTime) {
                // cout<<"Here";
                counter++;
                endTime = intervals[i][1];
            } else if (intervals[i][1] <= endTime) {
                endTime = intervals[i][1];
            }
        }

        return intervals.size() - counter;
    }
};
