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
    int mode; 
    vector<int> modeNodes;
    int prev; 
    int count;
    
    void modeRec(TreeNode *node, bool addNodes = false) {
        if (!node) {
            return;
        }
        
        modeRec(node->left, addNodes);
        // cout << prev << " " << node->val << "\n";
        if (prev == node->val) {
            count++;
        } else {
            count = 1;
        }
        // cout << "C: " << count << " " << mode << endl;
        if (!addNodes) {
            mode = max(mode, count);
        } else if (count == mode) {
            modeNodes.push_back(node->val);
        }
        prev = node->val;
        modeRec(node->right, addNodes);
    }
    

    vector<int> findMode(TreeNode* root) {
        mode = INT_MIN;
        prev = INT_MIN;
        count = 1;
        modeRec(root);
        // cout << mode << endl;
        count = 1;
        prev = INT_MIN;
        modeRec(root, true);
        return modeNodes;
    }
};
