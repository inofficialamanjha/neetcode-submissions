class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> graph;

        // Graph Construction
        for (auto num : nums) {
            // Ensure the node exists
            if (!graph.count(num))
                graph[num] = false;

            // num -> num - 1
            if (graph.count(num - 1)) {
                graph[num] = true;
            }

            // If num already exists as a predecessor,
            // connect num + 1 -> num
            if (graph.count(num + 1)) {
                graph[num + 1] = true;
            }
        }

        unordered_map<int, int> seqLength;
        int longestSequence = 0;

        for (auto& [num, _] : graph) {
            int length = fillSeqLen(graph, seqLength, num);
            longestSequence = max(longestSequence, length);
        }

        return longestSequence;
    }

    int fillSeqLen(
        unordered_map<int, bool>& graph,
        unordered_map<int, int>& seqLength,
        int key)
    {
        // Already calculated
        if (seqLength.count(key))
            return seqLength[key];

        // No node
        if (!graph.count(key))
            return 0;

        if (graph[key]) {
            // key -> key - 1
            seqLength[key] =
                1 + fillSeqLen(graph, seqLength, key - 1);
        }
        else {
            // Beginning of sequence
            seqLength[key] = 1;
        }

        return seqLength[key];
    }
};