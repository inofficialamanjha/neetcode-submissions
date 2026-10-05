class Solution {
public:
    unordered_map<
                string,
                priority_queue<string, vector<string>, greater<string>>
                > adj;
    
    vector<string> ans;

    void dfs(string u) {
        auto& pq = adj[u];

        while(!pq.empty()) {
            string v = pq.top();
            pq.pop();
            dfs(v);
        }

        ans.push_back(u);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto& ticket: tickets) {
            string u = ticket[0];
            string v = ticket[1];
            adj[u].push(v);
        }

        dfs("JFK");

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
