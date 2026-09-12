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
    int maxDiameter = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        func(root);
        return maxDiameter;
    }

    int func(TreeNode* root) {
        if (root==nullptr) {
            return 0; // This is the max diameter starting from root
        }

        if (root->left==nullptr && root->right==nullptr) {
            return 0;
        }

        int leftHeight = func(root->left);
        int rightHeight = func(root->right);

        int localMaxima = 0;
        if (root->left!=nullptr) {
            localMaxima += leftHeight + 1;
        }
        if (root->right!=nullptr) {
            localMaxima += rightHeight + 1;
        }

        maxDiameter = max(localMaxima, maxDiameter);

        return max(leftHeight+1, rightHeight+1);
    }
};
