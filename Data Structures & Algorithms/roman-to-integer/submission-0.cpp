class Solution {
public:
    int romanToInt(string& s, int current = 0) {
        if (current >= s.length()) {
            return 0;
        }

        char curr = s[current];

        char nextChar = '\0';

        if (current + 1 < s.length())
            nextChar = s[current + 1];

        switch (curr) {
            case 'I': {
                if (nextChar == 'V') {
                    return 4 + romanToInt(s, current + 2);
                } else if (nextChar == 'X') {
                    return 9 + romanToInt(s, current + 2);
                } else {
                    return 1 + romanToInt(s, current + 1);
                }
            }
            case 'V': {
                return 5 + romanToInt(s, current + 1);
            }
            case 'X': {
                if (nextChar == 'L') {
                    return 40 + romanToInt(s, current + 2);
                } else if (nextChar == 'C') {
                    return 90 + romanToInt(s, current + 2);
                } else {
                    return 10 + romanToInt(s, current + 1);
                }
            }
            case 'L': {
                return 50 + romanToInt(s, current + 1);
            }
            case 'C': {
                if (nextChar == 'D') {
                    return 400 + romanToInt(s, current + 2);
                } else if (nextChar == 'M') {
                    return 900 + romanToInt(s, current + 2);
                } else {
                    return 100 + romanToInt(s, current + 1);
                }
            }
            case 'D': {
                return 500 + romanToInt(s, current + 1);
            }
            case 'M': {
                return 1000 + romanToInt(s, current + 1);
            }
            default:
                return 0;
        }
    }
};