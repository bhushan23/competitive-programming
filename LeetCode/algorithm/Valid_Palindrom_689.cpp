class Solution {
public:
    
    bool palindrome(string &s, int from, int to, int count) {
        if (from >= to) {
            return true;
        }
        if (s[from] == s[to])
            return palindrome(s, from+1,to-1, count);
        else {
            return count > 0 && (palindrome(s, from,to-1, count-1) || palindrome(s, from+1,to, count-1));
        }
    }
    bool validPalindrome(string s) {
        return palindrome(s, 0, s.length()-1, 1);
    }
};
