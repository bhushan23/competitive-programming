class Solution {
public:
    int firstUniqChar(string s) {
        int ans = s.size();
        vector<int> mem(26, -1);
        for (int i = s.size() - 1; i >= 0; --i) {
            if (mem[s[i]-'a'] != -1) {
                mem[s[i]-'a'] = s.size();
            } else {
                mem[s[i]-'a'] = i;
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (mem[i] != -1) {
                ans = min(ans, mem[i]);
            }
        }
        return (ans == s.size() ? -1 : ans);
    }
};
