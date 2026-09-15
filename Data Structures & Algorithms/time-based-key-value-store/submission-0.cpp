class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {
        ;
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
string get(string key, int timestamp) {
    if (!mp.count(key))
        return "";

    vector<pair<int, string>>& lis = mp[key];

    int s = 0;
    int e = lis.size();

    while (s < e) {
        int mid = s + (e - s) / 2;

        if (lis[mid].first >= timestamp) {
            e = mid;          // mid can be the answer
        } else {
            s = mid + 1;      // mid cannot be the answer
        }
    }

    // s is first position >= timestamp
    if (s < lis.size() && lis[s].first == timestamp)
        return lis[s].second;

    // For TimeMap, we actually need <= timestamp
    if (s == 0)
        return "";

    return lis[s - 1].second;
}
};
