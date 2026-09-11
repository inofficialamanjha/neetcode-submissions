class Solution {
public:
    unordered_map<int, int> inorderIndex;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        int current = 0;
        int lowerLimit = 0;
        int upperLimit = inorder.size() - 1;
        return build(preorder, inorder, current, lowerLimit, upperLimit);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& current, int lowerLimit, int upperLimit)
    {
        if (lowerLimit > upperLimit) {
            return nullptr;
        }

        int rootIndex = inorderIndex[preorder[current]];
        TreeNode* head = new TreeNode(preorder[current]);

        current = current + 1;

        head->left = build(preorder, inorder, current, lowerLimit, rootIndex-1);
        head->right = build(preorder, inorder, current, rootIndex+1, upperLimit);

        return head;
    }
};