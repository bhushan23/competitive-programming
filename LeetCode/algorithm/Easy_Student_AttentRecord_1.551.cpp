class Solution {
public:
    bool checkRecord(string s) {
        int ACount = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'A') {
                ACount++;
                if (ACount > 1)
                    return false;
            } else if (i > 1 && s[i] == 'L' && s[i-1] == 'L' && s[i-2] == 'L') {
                return false;
            }
        }
        return true;
    }
};
