#define SIZE 62


class TrieNode {
    public:
        TrieNode *nodes[SIZE];
        bool nodesPresent[SIZE];
        string url;

    TrieNode() {
        for (int i = 0; i < SIZE; ++i) {
            nodes[i] = NULL;
            nodesPresent[i] = false;
        }
    }

};

class Solution {
public:
    
    
    TrieNode *headNode;
    string mapString = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        
    int CHAR(char ch) {
        if (ch >= '0' && ch <= '9')
            return ch-'0';
        if (ch >= 'a' && ch <= 'z')
            return ch-'a' + 10;
        if (ch >= 'A' && ch <= 'Z')
            return ch-'A'+36;
    }    
    void createTrieNodeRec(TrieNode *node, int d) {
        if (d == 1)
            return;
        for (int i = 0; i < SIZE; ++i) {
            node->nodes[i] = new TrieNode();
            node->nodesPresent[i] = false;
            createTrieNodeRec(node->nodes[i], d-1);
        }
    }
    Solution() {
        headNode = new TrieNode();
        createTrieNodeRec(headNode, 5);
    }
    
    string decodeUrl(string shortUrl, TrieNode *node, int i = 0) {
        if (i == 6) {
            return node->url;
        }
        
        int blk = CHAR(shortUrl[i]);
        assert (node->nodesPresent[blk] && "Node not present");
        
        return decodeUrl(shortUrl, node->nodes[blk], i+1);
    }
    
    bool checkAvailable(string &encoded, TrieNode *node, string &input, int i=0) {
        if (i == 6) {
            node->url = input;
            return true;
        }
        int blk = CHAR(encoded[i]);
        
        cout << "Char: " << encoded[i] << " " << blk << " D: " << i << "\n";
        if (node->nodesPresent[blk]) {
            return false;
        } 
        
        if (checkAvailable(encoded, node->nodes[blk], input, i+1)) {
            node->nodesPresent[blk] = true;
            return true;
        } else {
            return false;
        }
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        srand(time(NULL));
        string encoded(6,'-');
        
        do {
            for (int i = 0; i < 6; ++i) {
                encoded[i] = mapString[rand() % 62];
            }
            cout << "Check for: " << encoded << "\n";
        } while(!checkAvailable(encoded, headNode, longUrl));
        cout << "Encoded string " << encoded << "\n";
        return encoded;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decodeUrl(shortUrl, headNode);
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
