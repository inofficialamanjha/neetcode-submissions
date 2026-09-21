class DisjointSet {
    public:
        vector<int> size;
        vector<int> parent;

        DisjointSet(int numNodes) {
            size = vector<int>(numNodes+1, 1);
            parent = vector<int>(numNodes+1, 0);

            for(int i=1; i<numNodes+1; i++) {
                parent[i] = i; // Every node has the same parent initally
            }
        }

        int findParent(int key) {
            if (parent[key]==key) {
                return key;
            } else {
                int p = findParent(parent[key]);
                parent[key] = p;
                return p;
            }
        }

        void unionKeys(int key1, int key2) {
            int pk1 = findParent(key1);
            int pk2 = findParent(key2);
            int spk1 = size[pk1];
            int spk2 = size[pk2];

            if (spk1>=spk2) {
                parent[pk2] = pk1;
                size[pk1]+=size[pk2];
            } else {
                parent[pk1] = pk2;
                size[pk2]+=size[pk1];
            }
        }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int numNodes = edges.size();
        DisjointSet ds = DisjointSet(numNodes);

        for(auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];

            // Compute the parent for u and v - if the parent are same return
            if (ds.findParent(u)==ds.findParent(v)) {
                return edge; // this edge was not required, since they already has the same representative
            } else {
                // Union them
                ds.unionKeys(u, v);
            }
        }

        return edges[numNodes-1];
    }
};
