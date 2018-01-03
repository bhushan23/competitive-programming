class Solution {
public:
    int longestPalindrome(string s) {
        int odd = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            odd += count(s.begin(), s.end(), c) & 1;
            odd += count(s.begin(), s.end(), toupper(c)) & 1;
        }
        return s.length() - odd + (odd >= 1);
    }
};
