class Solution {
public:
    vector<vector<bool>> adj; // u->v means v is less than u
    vector<bool> contained;

    Solution() {
        adj = vector<vector<bool>>(26, vector<bool>(26, false));
        contained = vector<bool>(26, false);
    }

    string foreignDictionary(vector<string>& words) {
        int n = words.size();

        // Create adjacency graph
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                int index = calculate(words[i], words[j]);
                if (index==-1) {
                    return ""; 
                } else if (index==words[i].size()) {
                    ; // Do nothing
                } else {
                    int char2 = words[j][index] - 'a';
                    int char1 = words[i][index] - 'a';
                    adj[char2][char1] = true; // This edge is present
                }
            }
        }

        markContains(words);

        // Print adjacency graph
        for(int i=0; i<26; i++) {
            cout<<(char)(i+'a')<<" : ";
            for(int j=0; j<26; j++) {
                if(adj[i][j]) {
                    cout<<(char)(j+'a')<<", ";
                }
            }
            cout<<endl;
        }

        string lexographicalOrder = detectCycle();
        if (lexographicalOrder == "") {
            return "";
        } else {
            string ans = "";
            for(auto character: lexographicalOrder) {
                int pos = character - 'a';
                if (contained[pos]) {
                    ans+=character;
                }
            }
            return ans;
        }
    }

    void markContains(vector<string>& words) {
        for(int i=0; i<words.size(); i++) {
            for(int j=0; j<words[i].size(); j++) {
                contained[words[i][j]-'a'] = true;
            }
        }
    }

    int calculate(string& word1, string& word2) {
        int index = 0;

        while(index<word1.size() && index<word2.size()) {
            if (word1[index]==word2[index]) {
                ; // Do nothing
            } else {
                return index;
            }
            index++;
        }

        // One reached its end
        if(word1.size()>word2.size()) {
            return -1; // Not possible
        } else {
            return index; // both are equal
        }
    }

    string detectCycle() {
        vector<int> indegrees(26,0);

        for(int i=0; i<26; i++) {
            for(int j=0; j<26; j++) {
                if (adj[i][j]==true) {
                    indegrees[j]++;
                }
            }
        }

        string sorted = "";
        queue<int> bfs;

        for(int i=0; i<26; i++) {
            if (indegrees[i]==0) {
                bfs.push(i);
            }
        }

        while(!bfs.empty()) {
            int bfsFront = bfs.front();
            bfs.pop();
            sorted = (char)(bfsFront + 'a') + sorted;

            for(int i=0; i<26; i++) {

                if (adj[bfsFront][i]==true) {

                    indegrees[i]--;

                    if (indegrees[i]==0) {
                        bfs.push(i);
                    }
                }
            }
        }

        // It is expected that the sorted string contains all the elements
        if (26 == sorted.size()) {
            return sorted;
        } else {
            return "";
        }
    }
};
