class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size()%groupSize != 0) {
            return false;
        }

        map<int, int> count;

        for(auto card: hand) {
            count[card]++;
        }

        while(!count.empty()) {
            int startingCard = count.begin()->first;

            for(int card = startingCard; card < startingCard + groupSize; card++) {
                if (count.find(card) == count.end()) {
                    return false;
                }

                count[card]--;

                if (count[card]==0) {
                    count.erase(card);
                }
            }
        }

        return true;
    }
};
