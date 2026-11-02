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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root==nullptr) {
            return root;
        }

        if (root->val == key) {
            return rotate(root);
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }

    TreeNode* rotate(TreeNode* root) {
        TreeNode* returnNode = nullptr;
        if (root->left == nullptr && root->right == nullptr) {
            returnNode = nullptr;
        } else if (root->right==nullptr) {
            returnNode = root->left;
        } else if (root->left==nullptr) {
            returnNode = root->right;
        } else {
            TreeNode* head = root->right;
            while(head->left!=nullptr) {
                head = head->left;
            }
            head->left = root->left;
            returnNode = root->right;
        }

        delete root;
        return returnNode;
    }
};