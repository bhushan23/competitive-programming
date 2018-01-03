#define ISVOWEL(c) ((c =='a' || c== 'e' || c == 'i' || c == 'o' || c == 'u') || (c =='A' || c== 'E' || c == 'I' || c == 'O' || c == 'U'))
class Solution {
public:
    string reverseVowels(string s) {
        string out = s;
        for (int i = 0, j = s.length() - 1; i < j;) {
            if (ISVOWEL(out[i]) && ISVOWEL(out[j])) {
                swap(out[i], out[j]);
                i++;
                j--;
            } else if (!ISVOWEL(out[i]))
                i++;
            else if (!ISVOWEL(out[j]))
                j--;
        }
        return out;
    }
};
