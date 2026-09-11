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
    bool isValidBST(TreeNode* root, int lowerLimit = INT_MIN, int upperLimit = INT_MAX) {
        if (root==nullptr) {
            return true;
        }

        if (root->val > lowerLimit && root->val < upperLimit) {
            return isValidBST(root->left, lowerLimit, root->val) && isValidBST(root->right, root->val, upperLimit);
        }

        return false;
    }
};

/**
Validate Ranges for the left and right
**/
