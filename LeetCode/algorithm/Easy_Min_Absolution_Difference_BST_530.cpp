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
    int minDiff;
    int lastEl;
    
    Solution() {
        minDiff = INT_MAX;
        lastEl = -1;
    }
    
    void minRec(TreeNode *root) {
        if (!root)
            return;
        
        minRec(root->left);
        if (lastEl != -1) {
            minDiff = min(minDiff, abs(lastEl - root->val));
        }
        lastEl = root->val;
        
        minRec(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        minRec(root);
        return minDiff;
    }
};
