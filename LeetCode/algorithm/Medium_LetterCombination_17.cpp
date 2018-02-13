class Solution {
public:
    unordered_map<int, string> numbering;
    vector<string> out;
        
    
    Solution() {
        int counter = 0;
        for (int i = 2; i <= 9; ++i) {
            int t = 3;
            if (i == 7 || i == 9) {
                t =4;
            }
            for (int j = 0; j < t; ++j) {
                numbering[i] += 'a' + counter;
                counter++;
            }
        }
    }
    
    void recAdd(string &digits, int i, string &tempSt)  {
        if (i == digits.size()) {
            out.push_back(tempSt);
        }
        for (int j = 0; j < numbering[digits[i]-'0'].size(); ++j) {
            tempSt[i] = numbering[digits[i]-'0'][j];
            recAdd(digits, i+1, tempSt);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return out;
        string newComb(digits.size(), '-');
        recAdd(digits, 0, newComb);        
        return out;
    }
};
