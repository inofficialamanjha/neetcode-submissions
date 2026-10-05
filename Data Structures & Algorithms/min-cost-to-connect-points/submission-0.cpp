class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        vector<bool> visited(n, false);

        // {cost, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        pq.push({0, 0});

        int cost = 0;
        int count = 0;

        while (count < n) {

            auto [edgeCost, u] = pq.top();
            pq.pop();

            if (visited[u])
                continue;

            visited[u] = true;
            count++;
            cost += edgeCost;

            // Add edges from the newly added node
            for (int v = 0; v < n; v++) {

                if (!visited[v]) {

                    int dist =
                        abs(points[u][0] - points[v][0]) +
                        abs(points[u][1] - points[v][1]);

                    pq.push({dist, v});
                }
            }
        }

        return cost;
    }
};