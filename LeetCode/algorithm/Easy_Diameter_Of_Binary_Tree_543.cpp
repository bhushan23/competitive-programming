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
    int maxDist; 
    
    int findRec(TreeNode *root) {
        if (!root)
            return 0;
        int left = findRec(root->left);
        int right = findRec(root->right);
        
        maxDist = max(maxDist, left+right);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxDist = 0;
        findRec(root);
        return maxDist;
    }
};
