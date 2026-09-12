class Solution {
public:
    unordered_map<int, vector<int>> adj;
    vector<int> visited;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        for (auto& prereq : prerequisites) {
            int course = prereq[0];
            int prerequisite = prereq[1];

            // Reverse direction
            adj[prerequisite].push_back(course);
        }

        visited.resize(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {

            if (visited[i] == 0) {

                if (checkCycle(i)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool checkCycle(int vertex) {

        // Currently in the DFS path
        if (visited[vertex] == 1) {
            return true;
        }

        // Already completely processed
        if (visited[vertex] == 2) {
            return false;
        }

        // Mark as currently visiting
        visited[vertex] = 1;

        for (auto& node : adj[vertex]) {

            if (checkCycle(node)) {
                return true;
            }
        }

        // Finished processing this vertex
        visited[vertex] = 2;

        return false;
    }
};