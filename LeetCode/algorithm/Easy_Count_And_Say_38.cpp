class Solution {
public:
    string countAndSay(int n) {
        string out = "1";
        int i = 1;
        while (--n) {
            string cur = "";
            for (int i = 0; i < out.size(); ++i) {
                int count = 1;
                while (i + 1 < out.size() && out[i] == out[i+1]) {
                    count++;
                    i++;
                }
                cur += to_string(count) + out[i];
            }
            out = cur;
        }
        return out;
    }
};
