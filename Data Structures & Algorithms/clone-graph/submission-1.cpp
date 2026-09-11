class Solution {
public:
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;

        // Already cloned
        if (visited.count(node))
            return visited[node];

        // Create clone
        Node* clone = new Node(node->val);
        visited[node] = clone;

        // Clone all neighbors
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};