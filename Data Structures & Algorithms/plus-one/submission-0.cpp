class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int carry = 1;
        for(int i=digits.size()-1; i>=0; i--) {
            int total = digits[i] + carry;
            ans.insert(ans.begin(), total%10);
            carry = total/10;
        }
        if (carry!=0) {
            ans.insert(ans.begin(), carry);
        }
        return ans;
    }
};
