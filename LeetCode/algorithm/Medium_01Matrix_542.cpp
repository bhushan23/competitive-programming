class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = ( m > 0 ? matrix[0].size() : 0);
        vector<vector<int>> out(m, vector<int>(n, INT_MAX-1000));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    out[i][j] = 0;
                } else {
                    if (i > 0) {
                        out[i][j] = min(out[i][j], out[i-1][j]+1);
                    }

                    if (j > 0) {
                        out[i][j] = min(out[i][j], out[i][j-1]+1);
                    }
                }
            }
        }

        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                if (i < m-1) {
                    out[i][j] = min(out[i][j], out[i+1][j]+1);
                }

                if (j < n-1) {
                    out[i][j] = min(out[i][j], out[i][j+1]+1);
                }
            }
        }
        return out;
    }
};
