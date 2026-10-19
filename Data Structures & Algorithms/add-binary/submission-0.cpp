class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() < b.length()) {
            return addBinary(b, a);
        }

        // Assuming a is greater than b in length
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int carry = 0;

        for(int i=0; i<a.length(); i++) {
            int sum = a[i] - '0';
            if (i < b.length()) {
                sum += b[i] - '0';
            }
            sum += carry;

            if (sum<2) {
                carry = 0;
                a[i] = sum + '0';
            } else {
                carry = 1;
                if (sum==2) {
                    a[i] = '0';
                } else {
                    a[i] = '1';
                }
            }
        }

        if (carry==1) {
            a.push_back('1');
        }

        reverse(a.begin(), a.end());

        return a;
    }
};