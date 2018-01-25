class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {

        bool ans = true;
        for (int i = 0; i < bits.size()-1; i++) {
            if (!ans) {
                ans = true;
                continue;
            } else if (bits[i] == 0) {
                ans = true;
                continue;
            }
            if (bits[i] == 1) {
                ans = false;
            }
        }
        return ans;
    }
};
