class Solution {
public:
    
    // Reference: https://leetcode.com/problems/decode-ways/discuss/30358
    int numDecodings(string s) {
        #define VALID(X) (X >= 1 && X <= 26) 
        vector<int> dp(s.size()+1, 0);
        
        if (s.size() == 0)
            return 0;
        
        dp[0] = 1;
        dp[1] = (s[0] > '0' ? 1 : 0);
        
        for (int i = 2; i <= s.size(); ++i) {
            int one = stoi(s.substr(i-1, 1));
            int second = stoi(s.substr(i-2, 2));
            if (one >= 1 && one <= 9) {
                dp[i] += dp[i-1];
            }
            if (second >= 10 && second <= 26) {
                dp[i] += dp[i-2];
            }
        }
        return dp[s.size()];        
    }
};
