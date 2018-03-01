class Solution {
public:

    #define fin(x, y) (matrix[x][y]-'0')
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = (m > 0 ? matrix[0].size() : 0);

        int maxSide = 0;
        for (int i = 0; i < n; ++i) {
            maxSide = max(fin(0, i), maxSide);
        }
        for (int i = 0; i < m; ++i) {
            maxSide = max(fin(i, 0), maxSide);
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == '0') {
                    continue;
                }
                matrix[i][j] = matrix[i][j] + min(fin(i-1, j), min(fin(i, j-1), fin(i-1, j-1)));
                maxSide = max(fin(i, j), maxSide);
            }
        }
        return maxSide*maxSide;
    }
};
