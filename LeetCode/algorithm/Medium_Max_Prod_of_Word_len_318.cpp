class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> wordInts(words.size(), 0);
        
        if (words.size() < 2)
            return 0;
        
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].length(); ++j) {
                wordInts[i] |= (1 << (words[i][j]-'a'));
            }
            
        }
        
        int max = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i+1; j < words.size(); ++j) {
                if ((wordInts[i] ^ wordInts[j]) == (wordInts[i] | wordInts[j])) {
                    int prod = words[i].size() * words[j].size();
                    if (prod > max)
                        max = prod;
                }
            }
        }
        return max;
    }
};
