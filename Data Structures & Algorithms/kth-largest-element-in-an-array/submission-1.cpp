struct Compare {
    bool operator()(int a, int b) {
        return a > b;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, Compare> pq;

        for(int i=0; i<nums.size(); i++) {
            if (i<k) {
                pq.push(nums[i]);
                // cout<<"Push: "<<nums[i]<<endl;
            } else {
                if (nums[i] > pq.top()) {
                    // cout<<"Pop: "<<pq.top()<< ", and Push: "<<nums[i];
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }

        return pq.top();
    }
};
