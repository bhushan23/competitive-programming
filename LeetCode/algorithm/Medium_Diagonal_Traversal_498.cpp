class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = (m > 0 ? matrix[0].size() : 0 );
        vector<int> out(m*n, 0);
        int cnt = 0;
        int x, y;
        for (int i = 0; i < m+n-1; ++i) {
            int row = max(0, i-n+1);
            int col = min(i, n-1);
            int pCnt = cnt;
            
            for (; row < m && col >= 0; row++, col--) {
                out[cnt++] = matrix[row][col];    
            }
            if (i % 2 == 0) {
                reverse(out.begin()+pCnt, out.begin() + cnt);
            }
        }
        return out;
    }
};
