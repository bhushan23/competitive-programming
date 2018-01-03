class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(52, 0);
        
        for (auto ch : s) {
            if (isupper(ch)) {
                count[ch-'A'+26]++;
            } else {
                count[ch-'a']++;
            }
        }
        int total = 0;
        int odds = 0;
        
        for (int i = 0; i < 52; ++i) {
            if (count[i] % 2 == 1) {
                total += count[i] - 1;
                count[i] = 1;
                odds++;        
            } else {
                total += count[i];
            }
        }
        
       if (odds >= 1)
           total++;
        
        return total;
    }
};
