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

    TreeNode *addNodeRec(TreeNode *root, int v, int d, int c) {
        if (!root) {
            return NULL;
        }

        if (c == d) {
            TreeNode *lNode = new TreeNode(v);
            TreeNode *rNode = new TreeNode(v);

            lNode->left = root->left;
            rNode->right = root->right;

            if (root)
                root->left = lNode;

            if (root)
                root->right = rNode;
            if (root)
                return root;
            return lNode;
        }
        root->left = addNodeRec(root->left, v, d, c+1);
        root->right = addNodeRec(root->right, v, d, c+1);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode *nRoot = new TreeNode(v);
            nRoot->left = root;
            return nRoot;
        }
        return addNodeRec(root, v, d-1, 1);
    }
};
