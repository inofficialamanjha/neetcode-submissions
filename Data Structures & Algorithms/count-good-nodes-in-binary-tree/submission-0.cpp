class Solution {
public:
    stack<int> lastMax;

    int goodNodes(TreeNode* root) {
        if (!root)
            return 0;

        int maxSoFar = root->val;

        if (!lastMax.empty())
            maxSoFar = max(maxSoFar, lastMax.top());

        int ans = 0;

        if (lastMax.empty() || root->val >= lastMax.top())
            ans = 1;

        lastMax.push(maxSoFar);

        ans += goodNodes(root->left);
        ans += goodNodes(root->right);

        lastMax.pop();

        return ans;
    }
};