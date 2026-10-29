class Solution {
public:
    unordered_map<char, pair<int, int>> intervals;

    vector<int> partitionLabels(string s) {

        for(int i=0; i < s.size(); i++) {
            char ch = s[i];
            if (intervals.count(ch)) {
                intervals[ch] = {intervals[ch].first, i};
            } else {
                intervals[ch] = {i, i};
            }
        }

        // Now I need to merge intervals
        vector<pair<int, int>> itrvls;
        for(auto& interval: intervals) {
            itrvls.push_back(interval.second);
            // cout<<interval.first<<" "<<interval.second.first<<" "<<interval.second.second<<endl;
        }

        return getIntervalCount(itrvls);
    }

    vector<int> getIntervalCount(vector<pair<int, int>>& itrvls) {
        // Merge intervals and get count
        sort(itrvls.begin(), itrvls.end());
        int end = itrvls[0].second;
        int start = itrvls[0].first;
        vector<int> ans;

        for(int i=1; i<itrvls.size(); i++) {
            if (itrvls[i].first <= end) {
                // Merge them
                end = max(end, itrvls[i].second);
            } else {
                ans.push_back(end - start + 1);
                start = itrvls[i].first;
                end = itrvls[i].second;
            }
        }

        ans.push_back(end - start + 1);
        return ans;
    }
};
