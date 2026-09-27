class Solution {
public:
    unordered_map<int, int> distance;
    unordered_map<int, vector<pair<int, int>>> adj;

    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        for(int i=0; i<n; i++) {
            distance[i] = INT_MAX;
        }

        for(auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            adj[u].push_back({v, weight});
        }

        priority_queue<pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>> pq;

        distance[src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {
            auto [currDist, u] = pq.top();
            pq.pop();

            if (currDist > distance[u]) {
                continue;
            }

            for(auto [v, weight] : adj[u]) {
                // Update the distances, and push them to the priority queue
                if (weight + currDist < distance[v]) {
                    distance[v] = weight + currDist;
                    pq.push({distance[v], v});
                }
            }
        }

        for(int i=0; i<n; i++) {
            distance[i] = (distance[i] == INT_MAX) ? -1 : distance[i];
        }

        return distance;
    }
};
