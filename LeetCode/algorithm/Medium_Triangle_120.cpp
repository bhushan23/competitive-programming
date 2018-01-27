class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();

        vector<vector<int>> out(m, vector<int>(m, 0));
        out[0][0] = triangle[0][0];

        for (int i = 1; i < m; ++i) {
            out[i][0] = out[i-1][0] + triangle[i][0];
            out[i][i] = out[i-1][i-1] + triangle[i][i];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < i; ++j) {
                out[i][j] = min(out[i-1][j-1], out[i-1][j]) + triangle[i][j];
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < m; ++i) {
            ans = min(ans, out[m-1][i]);
        }
        return ans;
    }
};
