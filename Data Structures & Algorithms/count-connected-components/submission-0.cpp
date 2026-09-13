class Solution {
public:
    vector<vector<int>> adjList;
    vector<bool> visited;

    int countComponents(int n, vector<vector<int>>& edges) {
        visited = vector<bool>(n, false);
        adjList = vector<vector<int>>(n);  // FIX 1

        for(auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int connected = 0;
        queue<int> bfs;

        for(int i = 0; i < n; i++) {
            if (!visited[i]) {
                connected++;              // FIX 2

                bfs.push(i);
                visited[i] = true;        // FIX 3

                while(!bfs.empty()) {
                    int current = bfs.front();
                    bfs.pop();             // FIX 4

                    for(auto v: adjList[current]) {
                        if (!visited[v]) {
                            visited[v] = true; // FIX 5
                            bfs.push(v);
                        }
                    }
                }
            }
        }

        return connected;
    }
};