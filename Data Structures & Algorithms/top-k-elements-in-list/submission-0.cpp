class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for(auto num: nums) {
            counter[num]++;
        }

        vector<pair<int, int>> ans;
        for(auto _counter : counter) {
            ans.push_back(make_pair(_counter.second, _counter.first));
        }

        sort(ans.begin(), ans.end(), [](const auto& a, const auto &b) {
            return a.first > b.first;
        });

        vector<int> kAns;
        for(int i=0; i<k; i++) {
            kAns.push_back(ans[i].second);
        }
        return kAns;
    }
};
