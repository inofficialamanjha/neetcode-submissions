class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> fleets;

        int size = position.size();

        for (int i = 0; i < size; i++) {
            fleets.push_back({position[i], speed[i]});
        }

        // Closest to target first
        sort(fleets.begin(), fleets.end(),
             [](const auto& a, const auto& b) {
                 return a.first > b.first;
             });

        int counter = 1;

        double prevTime =
            (double)(target - fleets[0].first) / fleets[0].second;

        for (int i = 1; i < size; i++) {

            double currentTime =
                (double)(target - fleets[i].first) / fleets[i].second;

            if (currentTime <= prevTime) {
                // This car catches the fleet ahead
                continue;
            }

            // This car cannot catch the fleet ahead
            prevTime = currentTime;
            counter++;
        }

        return counter;
    }
};