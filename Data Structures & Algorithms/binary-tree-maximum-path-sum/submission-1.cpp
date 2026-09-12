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
    int globalMax;

    Solution() {
        globalMax = INT_MIN;
    }

    int maxPathSum(TreeNode* root) {
        return max(globalMax, func(root));
    }

    int func(TreeNode* root) {
        if (root==nullptr) {
            return 0;
        }

        int leftDiameterMax = func(root->left);
        int rightDiameterMax = func(root->right);

        // PartI: Calculate the maximum diagnoal including the root
        int maxDiameter = root->val;
        maxDiameter = max(maxDiameter, root->val + leftDiameterMax);
        maxDiameter = max(maxDiameter, root->val + rightDiameterMax);

        // PartII: See the local maximum - this can include both diagonals
        int localMaxima = root->val;
        localMaxima = max(localMaxima, root->val + leftDiameterMax + rightDiameterMax);

        globalMax = max(localMaxima, globalMax);

        // cout << root->val << " "<<leftDiameterMax<<" "<<rightDiameterMax<<" "<<maxDiameter<<" "<<globalMax<<endl;

        return maxDiameter;
    }
};
