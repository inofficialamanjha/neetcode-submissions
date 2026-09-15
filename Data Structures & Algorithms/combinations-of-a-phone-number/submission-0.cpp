class Solution {
public:
    vector<string> ans;
    string combo;

    string keypad[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        if (digits.size()==0) {
            return vector<string>();
        }
        combo = "";
        generateCombination(digits);
        return ans;
    }

    void generateCombination(string& digits, int index = 0) {
        if (index==digits.size()) {
            ans.push_back(combo);
            cout<<combo<<" ";
            return;
        }

        for(int i=0; i<keypad[digits[index] - '0'].size(); i++) {
            combo.push_back(keypad[digits[index] - '0'][i]);
            generateCombination(digits, index + 1);
            combo.pop_back(); // Back tracking
        }
    }
};
