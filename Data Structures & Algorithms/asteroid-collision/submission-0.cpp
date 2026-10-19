
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;

        for (int asteroid : asteroids) {
            bool alive = true;

            while (alive && asteroid < 0 && !stk.empty() && stk.top() > 0) {
                if (stk.top() < -asteroid) {
                    stk.pop();
                } else if (stk.top() == -asteroid) {
                    stk.pop();
                    alive = false;
                } else {
                    alive = false;
                }
            }

            if (alive) {
                stk.push(asteroid);
            }
        }

        vector<int> ans;
        while (!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
