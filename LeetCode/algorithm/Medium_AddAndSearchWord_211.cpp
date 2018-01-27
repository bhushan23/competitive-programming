class WordDictionary {
public:
    /** Initialize your data structure here. */
    class TrieNode {
        public:
            vector<TrieNode*> nodes;
            bool Present;
        TrieNode() {
            nodes.resize(26, NULL);
            Present = false;
        }


        void insert(string &word, int index) {
            TrieNode *node = this;
            while (node->nodes[word[index]-'a'] != NULL) {
                node = node->nodes[word[index]-'a'];
                index++;
                if (index == word.size()) {
                    return;
                }
            }
            while (index < word.size()) {
                TrieNode *tNode = new TrieNode();
                node->nodes[word[index]-'a'] = tNode;
                index++;
                node = tNode;
            }
            node->Present = true;
        }

        bool search(string &word, int index) {
            TrieNode *node = this;

            if (word.size() == index) {
                return Present;
            }

            if (word[index] == '.') {
                for (int i = 0; i < 26; ++i) {
                    if (nodes[i] == NULL)
                        continue;
                    if (nodes[i] != NULL && nodes[i]->search(word, index+1)) {
                        return true;
                    }
                }
            } else {
                if (nodes[word[index]-'a'] != NULL && index < word.size()) {
                    if (nodes[word[index]-'a']->search(word, index+1)) {
                        return true;
                    }
                }
            }
            return false;
        }

    };


    TrieNode *root;
    WordDictionary() {
        root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        root->insert(word, 0);
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return root->search(word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
