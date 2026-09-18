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

    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        func(root, 0, view);
        return view;
    }

    void func(TreeNode* head, int level, vector<int>& view) {
        if (head==nullptr) {
            return;
        }

        if (view.size()<level+1) {
            view.push_back(head->val);
        } else {
            view[level] = head->val;
        }

        func(head->left, level+1, view);
        func(head->right, level+1, view);
    }
};
