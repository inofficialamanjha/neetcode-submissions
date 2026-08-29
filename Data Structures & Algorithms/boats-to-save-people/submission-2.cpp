class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // Optimize : Reduce the number of boats, such that each boat can carry two-people and the sum of weights is less than limit
        int ans = 0;
        sort(people.begin(), people.end(), [](const auto& a, const auto &b) {
            return a > b; // Descending order
        }); // order doesn't matter

        // 3 2 2 1
        int i = 0;
        int j = people.size()-1;
        int currentWeight = 0;
        int count = 0;

        while(i<=j) {
            if (count==2) {
                currentWeight = 0;
                count = 0;
                ans++;
            }

            if (people[i] + currentWeight > limit) {
                if (people[j] + currentWeight <= limit) {
                    currentWeight += people[j];
                    j--;
                    count++;
                } else {
                    currentWeight = 0;
                    count = 0;
                    ans++;
                }
            } else {
                currentWeight += people[i];
                i++;
                count++;
            }
        }

        if (currentWeight>0) {
            ans++;
        }

        // Now let's follow greedy apprach
        return ans;
    }
};