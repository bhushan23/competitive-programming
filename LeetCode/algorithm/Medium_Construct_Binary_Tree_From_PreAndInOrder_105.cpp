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
    unordered_map<int, int> iMap;
    
    TreeNode * buildTreeRec(vector<int> &p, vector<int> &i, int &index, int from, int to) {
        
        if (index >= p.size() || from > to)
            return NULL;
        
        TreeNode *node = new TreeNode(p[index]);
        int nIndex = iMap[p[index]];
        
        if (nIndex > from ) {
            node->left = buildTreeRec(p, i, ++index, from, nIndex);
        } else {
            node->left = NULL;
        }
    
        if (nIndex < to-1) {
            node->right = buildTreeRec(p, i, ++index, nIndex+1, to);
        } else {
            node->right = NULL;
        }
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0)
            return NULL;
        for (int i = 0; i < inorder.size(); ++i) {
            iMap[inorder[i]] = i;
        }
        int index = 0;
        return buildTreeRec(preorder, inorder, index, 0, inorder.size());
    }
};
