class Solution {
public:
    string paran = "";
    vector<string> ans;

    vector<string> generateParenthesis(int n) {
        generate(n);
        return ans;
    }

    void generate(int n, int left=0, int right=0) {
        // cout<<paran<<" "<<left<<" "<<right<<endl;

        if (left-right<0) {
            return;
        }

        if (left+right >= 2*n) {
            if (left-right==0 && left+right==2*n) {
                ans.push_back(paran);
            }
            return;
        }

        if (left<n) {
            paran.push_back('(');
            generate(n, left+1, right);
            paran.pop_back();
        }

        if (right<n) {
            paran.push_back(')');
            generate(n, left, right+1);
            paran.pop_back();
        }
    }
};


