/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return getHeightAndBalance(root).second;
    }

    pair<int, bool> getHeightAndBalance(TreeNode* root) {
        if (root==nullptr) {
            return {0, true};
        }

        auto left = getHeightAndBalance(root->left);
        auto right = getHeightAndBalance(root->right);

        if (abs(left.first - right.first)>1) {
            return {max(left.first, right.first) + 1, false};
        } else {
            return {max(left.first, right.first) + 1, left.second && right.second};
        }
    }
};
