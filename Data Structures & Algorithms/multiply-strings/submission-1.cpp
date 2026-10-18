class Solution {
public:
    string multiply(string num1, string num2) {
        string ans = "";

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for(int j=0; j<num2.size(); j++) {
            // j moves num2
            int startIndex = j;
            int carry = 0;
            int intJ = (int)(num2[j] - '0');

            for(int i=0; i<num1.length(); i++) {
               // i moves nums1
                int intI = (int)(num1[i] - '0');
                int product = (intJ * intI) + carry;

                if (startIndex < ans.size()) {
                    product += (int)(ans[startIndex] - '0');
                }

                carry = product/10;
                product = product%10;

                // Product will set at the current Index
                addToString(ans, startIndex, (char)(product + '0'));
                startIndex++;
            }

            if (carry != 0) {
                addToString(ans, startIndex, (char)(carry + '0'));
            }
        }

        reverse(ans.begin(), ans.end());

        // Optimize the answer - by removing all end zeroes

        for(int i = 0; i<ans.size(); i++) {
            if (ans[i]!='0') {
                return ans.substr(i);
            }
        }

        return "0";
    }

    void addToString(string &s, int index, char character) {
        if (index == s.size()) {
            s.push_back(character);
        }

        s[index] = character;
    }
};

/**
3, 2, 1
4, 5

2, 4, 4
**/


