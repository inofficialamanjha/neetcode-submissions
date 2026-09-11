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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       // left mean -1, right means 1, itself means 0
       int pPos = 0;
       if (p==root) {
        return root;
       } else if (p->val < root->val) {
        pPos = -1;
       } else {
        pPos = 1;
       }

       int qPos = 0;
       if (q==root) {
        return root;
       } else if (q->val < root->val) {
        qPos = -1;
       } else {
        qPos = 1;
       }

       // If Both are left or both are right move that direction
       // If Both are opposite - the there it is - ans
       if (pPos != qPos) {
        return root;
       } else if (pPos == -1) {
        return lowestCommonAncestor(root->left, p, q);
       } else {
        return lowestCommonAncestor(root->right, p, q);
       }
    }
};

/**
Since, we are taling about ancestors - its the lowest in depth node, that actually creates the
bifercation between the two numbers
**/
