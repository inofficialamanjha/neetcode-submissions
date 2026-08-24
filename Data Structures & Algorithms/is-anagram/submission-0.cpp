class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> alphabet_counter(26,0);

        if(s.length() != t.length())
            return false;
        
        for(int i=0; i<s.length(); i++) {
           alphabet_counter[s[i]-'a']++;
           alphabet_counter[t[i]-'a']--; 
        }
        
        for(int i=0; i<alphabet_counter.size(); i++)
            if (alphabet_counter[i]!=0)
                return false;
        
        return true;
    }
};
