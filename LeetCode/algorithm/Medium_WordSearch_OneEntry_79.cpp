int mEntry[] = {-1, 0, 1, 0, 0, +1, 0, -1};
#define VALID(x, y, m, n) (x >= 0 && y >= 0 && x < m && y < n)
class Solution {
public:
    int m, n;
    bool recExists(vector<vector<char>> &b, string &word, int x, int y, int cur) {

        if (cur == word.size())
            return true;

        for (int i = 0; i < 7; i += 2) {
            int xR = x+mEntry[i];
            int yR = y+mEntry[i+1];
            if (!VALID(xR, yR, m, n))
                continue;
            if (word[cur] == b[xR][yR]) {
                b[xR][yR] = '-';
                if (recExists(b, word, xR, yR, cur+1))
                    return true;
                b[xR][yR] = word[cur];
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = (m > 0 ? board[0].size() : 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    board[i][j] = '-';
                    bool ans = recExists(board, word, i, j, 1);
                    board[i][j] = word[0];
                    if (ans)
                        return true;
                }
            }
        }
        return false;
    }
};
