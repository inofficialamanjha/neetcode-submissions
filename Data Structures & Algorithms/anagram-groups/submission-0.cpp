class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;

        for(int i=0; i<strs.size(); i++) {
            string ref_string = strs[i];
            sort(ref_string.begin(), ref_string.end());
            anagrams[ref_string].push_back(strs[i]);
        }

        vector<vector<string>> groupedAnagrams;

        for(auto i: anagrams) {
            groupedAnagrams.push_back(i.second);
        }

        return groupedAnagrams;
    }
};
