class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> maxElement(3, INT_MIN);

        for (auto& triplet : triplets) {
            if (triplet[0] <= target[0] &&
                triplet[1] <= target[1] &&
                triplet[2] <= target[2]) {
                maxElement[0] = max(maxElement[0], triplet[0]);
                maxElement[1] = max(maxElement[1], triplet[1]);
                maxElement[2] = max(maxElement[2], triplet[2]);
            }
        }

        return maxElement == target;
    }
};