class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5 = 0, count10 = 0;

        for(int i=0; i<bills.size(); i++) {
            if (bills[i] == 5) {
                count5++;
            } else if (bills[i]==10) {
                // Return 5's
                if (count5 == 0) {
                    return false;
                }

                count5--;
                count10++;
            } else {
                if (count10 != 0) {
                    count10--; // 10 Change given - 10 left

                    if (count5==0) {
                        return false;
                    }

                    count5--;
                } else {
                    if(count5 < 3) {
                        return false;
                    }

                    count5 -= 3;
                }
            }
        }

        return true;
    }
};