/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

struct Compare {
    bool operator()(const Interval& a, const Interval& b) {
        return a.end > b.end; // Min heap
    }
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            if (a.start == b.start) {
                return a.end < b.end;
            }

            return a.start < b.start;
        });

        priority_queue<Interval, vector<Interval>, Compare> pq;

        for(int i=0; i<intervals.size(); i++) {
            if (pq.empty()) {
                pq.push(intervals[i]);
            } else {
                Interval top = pq.top();

                if (intervals[i].start >= top.end) {
                    // We can merge top
                    pq.pop();
                    top.end = intervals[i].end; // End updated
                    pq.push(top);
                } else {
                    // We know this cannot be added to the least possible end-time - and hence it will be a new entry
                    pq.push(intervals[i]);
                }
            }
        }

        return pq.size();
    }
};
