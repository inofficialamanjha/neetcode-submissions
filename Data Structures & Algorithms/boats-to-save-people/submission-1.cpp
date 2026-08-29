class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;

        sort(people.begin(), people.end(), [](const auto& a, const auto& b) {
            return a > b; // Descending
        });

        int i = 0;
        int j = people.size() - 1;

        int currentWeight = 0;
        int count = 0;

        while (i <= j) {

            // Boat already has 2 people
            if (count == 2) {
                ans++;
                currentWeight = 0;
                count = 0;
            }

            // Try to put the heaviest remaining person
            if (currentWeight + people[i] <= limit) {
                currentWeight += people[i];
                i++;
                count++;
            }
            // Otherwise try the lightest remaining person
            else if (currentWeight + people[j] <= limit) {
                currentWeight += people[j];
                j--;
                count++;
            }
            // Nobody can fit -> close the boat
            else {
                ans++;
                currentWeight = 0;
                count = 0;
            }
        }

        // Last partially filled boat
        if (count > 0) {
            ans++;
        }

        return ans;
    }
};