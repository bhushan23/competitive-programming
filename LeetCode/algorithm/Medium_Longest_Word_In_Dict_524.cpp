class Solution {
public:
    
    bool possible(string &main, string &sub) {
        int i = 0;
        int j = 0;
        int iLen = main.length();
        int jLen = sub.length();
        
        while (j < jLen && i < iLen) {
            if (main[i] == sub[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        return j == jLen;
    }
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end());
        
        string out;
        int maxLen = 0;
        for (string each : d) {
            if (possible(s, each) && each.length() > maxLen) {
                maxLen = each.length();
                out = each;
            }
        }
        return out;
    }
};
