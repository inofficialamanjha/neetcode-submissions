class Solution {
public:
    int findCheapestPrice(
        int n,
        vector<vector<int>>& flights,
        int src,
        int dst,
        int k
    ) {
        vector<int> dist(n, INT_MAX);

        dist[src] = 0;

        // At most k + 1 flights
        for (int i = 0; i < k + 1; i++) {
            int check = true;

            vector<int> temp = dist;

            for (auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int weight = flight[2];

                // u must be reachable using previous number of flights
                if (dist[u] == INT_MAX)
                    continue;

                if (dist[u] + weight < temp[v]) {
                    check = false;
                    temp[v] = dist[u] + weight;
                }
            }

            dist = temp;

            if (check == true) {
                // Early break;
                break;
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};