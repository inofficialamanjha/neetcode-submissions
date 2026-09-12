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
        if (data[pos]=='#') {
            pos++;
            return nullptr;
        }

        if (data[pos]==',') {
            pos++;
            return func(data, pos);
        }

        string intString = "";

        while(data[pos]!=',') {
            intString += data[pos];
            pos++;
        }

        TreeNode* head = new TreeNode(stoi(intString));
        head->left = func(data,pos);
        head->right = func(data,pos);
        return head;
    }
};