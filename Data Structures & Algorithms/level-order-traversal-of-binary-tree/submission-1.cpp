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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root==nullptr)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            vector<int> _ans;
            int queueSize = q.size();

            while(queueSize > 0) {
                TreeNode* current = q.front();
                q.pop();
                _ans.push_back(current->val);
                
                if (current->left!=nullptr)
                    q.push(current->left);

                if (current->right!=nullptr)
                    q.push(current->right);

                queueSize--;
            }

            ans.push_back(_ans);
        }

        return ans;
    }
};
