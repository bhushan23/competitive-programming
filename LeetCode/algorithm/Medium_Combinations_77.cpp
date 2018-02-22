class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> out;

        vector<int> temp(k, 0);
        int i = 0;

        while (i >= 0) {
            temp[i]++;
            if (temp[i] > n) {
                --i;
            } else if (i == k-1) {
                out.push_back(temp);
            } else {
                i++;
                temp[i] = temp[i-1];
            }
        }

        return out;
    }
};
