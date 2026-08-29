class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       vector<pair<int, int>> numArray;

       for(int i=0; i<nums.size(); i++) {
        numArray.push_back(make_pair(nums[i], i));
       }

       sort(numArray.begin(), numArray.end(), [](const auto& a, const auto& b){
        if (a.first == b.first) {
            return a.second < b.second; // Ascending by index
        } else {
            return a.first < b.first; // Ascending order
        }
       });

       for(int i = 1; i<numArray.size(); i++) {
        if (numArray[i].first == numArray[i-1].first) {
            if (numArray[i].second - numArray[i-1].second <= k) {
                return true;
            }
        }
       }

       return false;
    }
};