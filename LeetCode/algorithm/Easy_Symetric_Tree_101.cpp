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
    
    bool recCheck(TreeNode *left, TreeNode *right) {
        if (left == NULL && right == NULL)
            return true;
        if (left == NULL || right == NULL)
            return false;
        if (left->val != right->val)
            return false;
        
        return (recCheck(left->left, right->right) && recCheck(left->right, right->left));
        
    }
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return recCheck(root->left, root->right);
    }
};
