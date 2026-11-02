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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root==nullptr) {
            TreeNode* valNode = new TreeNode(val);
            return valNode;
        }

        TreeNode* insertedNode = nullptr;

        if (val < root->val) {
            // Left
            insertedNode = insertIntoBST(root->left, val);
            root->left = insertedNode;
        } else {
            insertedNode = insertIntoBST(root->right, val);
            root->right = insertedNode;
        }

        return root;
    }
};