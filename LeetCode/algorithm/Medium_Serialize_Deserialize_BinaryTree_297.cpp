/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> nodes;
        
        if (!root)
            return "";
        
        nodes.push(root);
        string serializedStr;
        
        while (!nodes.empty()) {
            TreeNode *tmp = nodes.front();
            nodes.pop();
            serializedStr += (tmp != NULL ? to_string(tmp->val) : "");
            serializedStr += ",";
            if (tmp) {
                nodes.push(tmp->left);
                nodes.push(tmp->right);
            }
        }
        return serializedStr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // cout << data;
        if (data.size() == 0)
            return NULL;
        
        TreeNode *root = NULL;
        queue<TreeNode *> nodeQ;
        int i = data.find_first_of(",");
        root = new TreeNode(stoi(data.substr(0, i)));
        i++;
        nodeQ.push(root);
        // cout << data.substr(0, i) << " " << root->val << "\n";
        do {
            
            TreeNode *tmp = nodeQ.front();
            nodeQ.pop();
            int lChild = 0;
            int rChild = 0;
            
            int l = i;
            bool isNeg = false;
            while (data[i] != ',') {
                if (data[i] == '-') {
                    i++;
                    isNeg = true;
                    continue;
                }
                lChild *= 10;
                lChild += data[i++] - '0';
            }
            if (l == i) {
                tmp->left = NULL;
            } else {
                if (isNeg) {
                    lChild *= -1;
                }
                TreeNode *left = new TreeNode(lChild);
                nodeQ.push(left);
                tmp->left = left;
            }
            i++; // SKIP ,
            
            l = i;
            isNeg = false;
            while (data[i] != ',') {
                if (data[i] == '-') {
                    i++;
                    isNeg = true;
                    continue;
                }
                rChild *= 10;
                rChild += data[i++] - '0';
            }
            if (l == i) {
                tmp->right = NULL;
            } else {
                if (isNeg) {
                    rChild *= -1;
                }
                TreeNode *right = new TreeNode(rChild);
                nodeQ.push(right);
                tmp->right = right;
            }
            i++; // SKIP ,
        } while (i < data.length());
        return root;   
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
