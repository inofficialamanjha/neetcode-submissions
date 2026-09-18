class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<bool>> adj(numCourses, vector<bool>(numCourses, false));
        vector<int> indegrees(numCourses, 0);

        for(auto& edge: prerequisites) {
            // [u, v] : graph exists from v->u
            adj[edge[1]][edge[0]] = true;

            indegrees[edge[0]]++;
        }

        vector<int> topo;
        queue<int> q;

        for(int i=0; i<numCourses; i++) {
            if (indegrees[i]==0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int front = q.front();
            topo.push_back(front);
            q.pop();

            for(int j=0; j<numCourses; j++) {
                if (adj[front][j]) {
                    indegrees[j]--;
                    if (indegrees[j]==0)
                        q.push(j);
                }
            }
        }

        return topo.size() == numCourses ? topo : vector<int>();
    }
};
