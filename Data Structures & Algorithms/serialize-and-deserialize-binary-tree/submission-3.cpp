/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if (root == nullptr)
            return "#";

        return to_string(root->val) + "," +
               serialize(root->left) + "," +
               serialize(root->right);
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        int pos = 0;

        return func(data, pos);
    }


    TreeNode* func(string& data, int& pos) {

        // Find end of current token
        int start = pos;

        while (pos < data.size() && data[pos] != ',')
            pos++;

        string value = data.substr(start, pos - start);

        // Move past comma
        if (pos < data.size())
            pos++;

        // NULL node
        if (value == "#")
            return nullptr;

        // Create node
        TreeNode* node = new TreeNode(stoi(value));

        // Reconstruct left and right
        node->left = func(data, pos);
        node->right = func(data, pos);

        return node;
    }
};