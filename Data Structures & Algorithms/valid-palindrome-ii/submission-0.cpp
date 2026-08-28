class Solution {
public:
    bool validPalindrome(string s) {
        if(isPalindrome(s)) {
            return true;
        }

        int i = 0, j = s.size() - 1;

        while(i<j) {
            if (s[i]!=s[j])
                break;
            
            i++; j--;
        }

        string s1 = "", s2 = "";
        for(int k=0; k<s.size(); k++) {
            if (k!=i) {
                s1 += s[k];
            }

            if (k!=j) {
                s2 += s[k];
            }
        }

        cout<<i<<" "<<j<<" "<<s1<<" "<<s2<<endl;

        return isPalindrome(s1) || isPalindrome(s2);
    }

    bool isPalindrome(string s) {
        string revS = s;
        reverse(s.begin(), s.end());
        if (s==revS) {
            return true;
        }

        return false;
    }
};