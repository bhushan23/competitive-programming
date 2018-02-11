class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length()-1;

        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        if (i == -1)
            return 0;
        int mode = i;
        for (; i >= 0; --i) {
            if (s[i] == ' ') {
                return mode-i;
            }
        }
        return mode+1;
    }
};
