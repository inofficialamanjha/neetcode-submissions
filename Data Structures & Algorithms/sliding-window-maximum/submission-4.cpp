struct Compare {
    bool operator()(const pair<int, int>& a,
                    const pair<int, int>& b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // first: index, value
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++) {
            while(!pq.empty() && pq.top().first <= i-k) {
                pq.pop();
            }

            pq.push({i, nums[i]});

            if (i>=k-1) {
                ans.push_back(pq.top().second);
            }
        }

        return ans;
    }
};
