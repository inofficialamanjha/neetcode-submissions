class Solution {
public:
    class GraphNode {
        public:
            bool visited;
            vector<int> edges;

            GraphNode() {
                visited = false;
            }
        
    };

    unordered_map<int, GraphNode> adjacencyList;

    bool validTree(int n, vector<vector<int>>& edges) {

        // Step I: Build the graph
        for(auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];

            adjacencyList[u].edges.push_back(v);
            adjacencyList[v].edges.push_back(u);
        }

        // Step II: Call the isConnected Function from 0
        if (!isConnected(0)) {
            return false;
        } else {
            // Check if all the nodes are visited
            for(auto& node: adjacencyList) {
                if (node.second.visited == false) {
                    return false; // A particular node is node visited
                }
            }
        }
        

        return true;
    }
    
    bool isConnected(int node, int parentNode = -1) {
        if (adjacencyList[node].visited == true) {
            return false;
        }

        adjacencyList[node].visited = true;

        for (auto& edge: adjacencyList[node].edges) {
            if (edge != parentNode) {
                if (!isConnected(edge, node)) {
                    return false;
                }
            }
        }

        return true;
    }
};

// A non cyclic graph is a tree
