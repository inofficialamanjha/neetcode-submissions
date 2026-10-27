class Solution {
public:
    unordered_map<int, unordered_map<int, int>> mp;

    int numDistinct(string& s, string& t, int start = 0, int current = 0) {
        if (current==t.size()) {
            return 1;
        }

        if(start==s.size()) {
            return 0;
        }

        int ways = 0;

        if(mp.count(start) && mp[start].count(current)) {
            return mp[start][current];
        }

        for(int i=start; i<s.size(); i++) {
            if (s[i]==t[current]) {
                ways += numDistinct(s, t, i+1, current + 1);
            }
        }

        mp[start][current] = ways;
        return ways;
    }
};
