class Solution {
public:

    unordered_map<int, vector<int>> adj;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        queue<int> topologicalSort;

        // StepI: Creating adjacency matrix
        for(auto& prerequisite: prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }

        // Step II: Prepping for topological sort
        int completed = 0;

        for(int i=0; i<numCourses; i++) {
            if (indegree[i]==0) {
                topologicalSort.push(i);
            }
        }

        while(!topologicalSort.empty()) {
            int top = topologicalSort.front();
            topologicalSort.pop();

            for(auto& node: adj[top]) {
                indegree[node]--;
                if (indegree[node]==0) {
                    topologicalSort.push(node);
                }
            }

            completed++;
        }

        return completed == numCourses;
    }
};
