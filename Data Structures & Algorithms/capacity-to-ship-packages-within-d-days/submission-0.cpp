class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int totalWeights = 0;
        int maxWeight = 0;

        for(int i=0; i<weights.size(); i++) {
            maxWeight = max(weights[i], maxWeight);
            totalWeights += weights[i];
        }

        // Range --> weight to totalWeight
        int s = maxWeight;
        int e = totalWeights;
        int weight = INT_MAX;

        while(s<=e) {
            int mid = s + (e-s)/2;
            
            int currentDays = numberOfDays(mid, weights);

            // cout<<mid<<" "<<currentDays<<" "<<weight<<endl;

            if ( currentDays <= days ) {
                // Valid scenario
                weight = min(weight, mid);
                // Let's decrease the weight to
                e = mid - 1;
            } else {
                // Let's increase the weight
                s = mid + 1;
            }

        }

        return weight;
    }

    int numberOfDays(int weight, vector<int>& weights) {
        int days = 0;
        int currentSum = 0;

        for(int i=0; i<weights.size(); i++) {
            if (currentSum + weights[i] <= weight) {
                currentSum += weights[i];
            } else {
                days++;
                currentSum = weights[i];
            }
        }

        if (currentSum!=0) {
            days++;
        }

        return days;
    }
};

/**
2, 6, 12, 13, 16, 26
**/