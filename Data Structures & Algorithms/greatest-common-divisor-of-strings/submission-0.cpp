class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str2.length() > str1.length()) {
            return gcdOfStrings(str2, str1);
        }

        cout<<str1<<" "<<str2<<endl;

        if (str2 == "") {
            return str1;
        }

        // The first string is bigger than the second
        int i = 0;
        int length = str2.length();

        while(i + length - 1 < str1.length()) {
            if (str1.substr(i, length)!=str2) {
                return "";
            } else {
                i += length;
            }
        }

        return gcdOfStrings(str2, str1.substr(i));
    }
};