/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> paths;
    
    void recPathAdd(TreeNode *node, string curPath = "") {
        if (!node) {
            return;
        }
        curPath += (curPath == "" ? "" : "->") + to_string(node->val);
        if (node->left)
            recPathAdd(node->left, curPath);
        if (node->right)
            recPathAdd(node->right, curPath);
        
        if (node->left == NULL && node->right == NULL)
            paths.push_back(curPath);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        recPathAdd(root);
        return paths;
    }
};
