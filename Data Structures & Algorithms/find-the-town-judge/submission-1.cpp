class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1, 0);
        vector<int> outdegree(n+1, 0);

        for(auto& edge: trust) {
            int u = edge[0];
            int v = edge[1];

            outdegree[u]++; // U sends his trust to V
            indegree[v]++; // V receives his trust from U
        }

        int label = -1;

        for(int i=1; i<=n; i++) {
            if (indegree[i]==n-1 && outdegree[i]==0) {
                //cout<<i<<" "<<indegree[i]<<" "<<outdegree[i]<<endl;
                if (label==-1) {
                    label = i;
                } else {
                    return -1;
                }
            }
        }

        return label;
    }
};