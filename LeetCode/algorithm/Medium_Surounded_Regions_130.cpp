#define VALID(x, y) (x >= 0 && x < m && y >= 0 && y < n)
#define ISEDGE(x, y) (x == 0 || y == 0 || x == m-1 || y == n-1)
class Solution {
public:
    int m, n;

    void dfs(vector<vector<char>>& board, int x, int y) {
        if (!VALID(x,y))
            return;

        int dir[] = {-1, 0, 1, 0, -1};
        board[x][y] = '-';
        for (int i = 0; i < 4; ++i) {
            int nX = x + dir[i];
            int nY = y + dir[i+1];
            if (VALID(nX, nY) && board[nX][nY] == 'O') {
                board[nX][nY] = '-';
                dfs(board, nX, nY);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = (m > 0 ? board[0].size() : 0);

        if (m <= 1 || n == 1)
            return;

        for (int i = 0; i < n; ++i) {
            if (board[0][i] == 'O') {
                dfs(board, 0, i);
            }
            if (board[m-1][i] == 'O') {
                dfs(board, m-1, i);
            }
        }
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (board[i][n-1] == 'O') {
                dfs(board, i, n-1);
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '-') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }

    }
};
