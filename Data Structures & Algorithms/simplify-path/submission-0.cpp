class Solution {
public:
    stack<string> paths;

    string simplifyPath(string path) {
        int i = 0;

        while(i<path.length()) {
            char current = path[i];

            if (current == '/') {
                i++; // Do nothing
            } else {
                int j = i;
                while(j < path.length() && path[j]!='/') {
                    j++; // j will reach the new '/' or the end
                }

                string str = path.substr(i, j-i);

                if (str == ".") {
                    ; // Do nothing
                } else if (str == "..") {
                    if (!paths.empty()) {
                        paths.pop();
                    }
                } else {
                    paths.push(str);
                }

                i = j;
            }
        }

        string ans = "";
        while(!paths.empty()) {
            ans = "/" + paths.top() + ans;
            paths.pop();
        }
        if (ans=="") {
            return "/"; // Return root if empty answer
        }
        return ans;
    }
};