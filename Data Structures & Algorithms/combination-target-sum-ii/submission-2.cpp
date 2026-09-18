class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> current;
        generate(candidates, target, current);
        return ans;
    }

    void generate(vector<int>& candidates, int target,
              vector<int>& currentSum, int sum = 0, int current = 0) {

    if (sum == target) {
        ans.push_back(currentSum);
        return;
    }

    if (sum > target || current >= candidates.size())
        return;

    // Take current
    currentSum.push_back(candidates[current]);
    generate(candidates, target, currentSum,
             sum + candidates[current], current + 1);
    currentSum.pop_back();

    // Skip current + all duplicates
    int next = current + 1;
    while (next < candidates.size() &&
           candidates[next] == candidates[current])
        next++;

    generate(candidates, target, currentSum, sum, next);
}
};
