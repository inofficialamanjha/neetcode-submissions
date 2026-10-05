class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> adj;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(auto& time: times) {
            int u = time[0];
            int v = time[1];
            int t = time[2];

            adj[u].push_back({t, v});
        }

        vector<int> distance = vector<int>(n+1, INT_MAX);
        distance[0] = 0;

        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, k});
        distance[k] = 0;

        while(!pq.empty()) {
            auto pqFront = pq.top();
            pq.pop();

            int u = pqFront.second;
            int dist = pqFront.first;

            for(auto& edge: adj[u]) {
                int t = edge.first;
                int v = edge.second;

                // Push to the priority queue - only if its distance is less
                if (dist + t < distance[v]) {
                    distance[v] = dist + t;
                    pq.push({distance[v], v});
                }
            }
        }

        int maxDistance = 0;
        for(int i=0; i<distance.size(); i++) {
            if (distance[i]==INT_MAX) {
                return -1;
            }

            maxDistance = max(distance[i], maxDistance);
        }

        return maxDistance;
    }
};
