class WordFilter {
public:
     class TrieNode {
        public:
            vector<TrieNode*> nodes;
            vector<int> nodeIndex;
        TrieNode() {
            nodes.resize(26, NULL);
        }

        void insert(string &word, int i, int nIndex) {
            nodeIndex.push_back(nIndex);
            if (word.size() == i)
                return;
            if (nodes[word[i]-'a'] == NULL) {
                nodes[word[i]-'a'] = new TrieNode();
            }
            nodes[word[i]-'a']->insert(word, i+1, nIndex);
         }

        vector<int> search(string &word, int index) {
            if (word.size() == index) {
                return nodeIndex;
            }
            if (index < word.size() && nodes[word[index]-'a'] != NULL) {
                return nodes[word[index]-'a']->search(word, index+1);
            }
            return {};
        }
     };

    TrieNode *pRoot;
    TrieNode *sRoot;
    int maxNodes;

    WordFilter(vector<string> words) {
        pRoot = new TrieNode();
        sRoot = new TrieNode();
        for (int i = 0; i < words.size(); ++i) {
            pRoot->insert(words[i], 0, i);
            reverse(words[i].begin(), words[i].end());
            sRoot->insert(words[i], 0, i);
        }
        maxNodes = words.size()-1;
    }

    int f(string prefix, string suffix) {
        vector<int> pSet = pRoot->search(prefix, 0);
        reverse(suffix.begin(), suffix.end());
        vector<int> sSet = sRoot->search(suffix, 0);

        auto pIt = pSet.rbegin();
        auto sIt = sSet.rbegin();
        while (pIt != pSet.rend() && sIt != sSet.rend()) {
            if (*pIt == *sIt) {
                return *pIt;
            } else if (*pIt > *sIt) {
                pIt++;
            } else {
                sIt++;
            }
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
