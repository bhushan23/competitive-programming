class Solution {
public:
    int m;
    int n;
    int avg(vector<vector<int>>& M, int i, int j) {
        int count = 0;
        int part = 0;
        for (int k = max(i-1, 0); k < min(i+2, m); ++k) {
            for (int l = max(j-1, 0); l < min(j+2, n); ++l) {
                count += M[k][l];
                part++;
            }    
        }
        return floor(count/part);
    }
    
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        m = M.size();
        n = (m > 0  ? M[0].size() : 0);
        vector<vector<int>> out(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                out[i][j] = avg(M, i, j);
            }
        }
        return out;
    }
};
