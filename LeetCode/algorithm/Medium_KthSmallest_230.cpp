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
    int count;
    
    Solution() {
        count = 0;
    }
    int kthSmallest(TreeNode* root, int k) {
        if (!root)
            return -1;

        int val = kthSmallest(root->left, k);
        if (val != -1) 
            return val;
        
        count++;
        
        if (k == count)
            return root->val;
        
        val = kthSmallest(root->right, k);
        if (val != -1)
            return val;

        return -1;
    }
};
