#define LOC(i) (i-'a')
class Trie {
public:
    /** Initialize your data structure here. */
    class Node {
        public:
        vector<Node *> element;
        bool exists;
        Node() {
            exists = false;
            element.resize(26, NULL);
        }
    };
    
    Node *Root;
    Trie() {
        Root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = Root;
        for (int i = 0; i < word.size(); ++i) {
            if (node->element[LOC(word[i])] == NULL) {
                node->element[LOC(word[i])] = new Node();
            }
            node = node->element[LOC(word[i])];
        }
        node->exists = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *node = Root;
        // cout << "SEARCHING " << word << "\n";
        for (int i = 0; i < word.size(); ++i) {
            if (node->element[LOC(word[i])] == NULL) {
                return false;
            } else {
                // cout << "Node: " << i+'a' << " " << node->exists<< "\n";
                node = node->element[LOC(word[i])];
            }
        }
        // cout << node->exists << "\n";
        return node->exists;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *node = Root;
        for (int i = 0; i < prefix.size(); ++i) {
            if (node->element[LOC(prefix[i])] == NULL) {
                return false;
            } else {
                node = node->element[LOC(prefix[i])];
            }
        }
        return node != NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
