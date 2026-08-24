class Solution {
public:
    bool isPalindrome(string s) {
       int f = 0;
       int r = s.size() - 1;

       while(f<=r) {
        char front = tolower(s[f]);
        char rear = tolower(s[r]);
        if (front!=rear) {
            if (!isalnum(front)) {
                f++;
                continue;
            }

            if (!isalnum(rear)) {
                r--;
                continue;
            }
            
            return false;
        } else {
            f++;
            r--;
        }
       }

       return true;
    }
};
