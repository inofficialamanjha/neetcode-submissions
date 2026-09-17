class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = 0;
        for(int i=0; i<piles.size(); i++) {
            e = max(e, piles[i]);
        }

        while(s!=e) {
            int mid = (s+e)/2;

            int current = 0;

            for(int i=0; i<piles.size();i++) {
                current+=ceil(piles[i]*1.0/mid);
            }

            // cout<<mid<<" "<<current<<endl;

            if (current <= h) {
                // We do have more time
                e = mid;
            } else {
                // Taking too much time - increase
                s = mid + 1;
            }
        }

        return s;
    }
};
