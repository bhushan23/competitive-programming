    
class Solution {
public:
    int m, n;
    bool recExists(vector<vector<char>> &b, string &word, int x, int y, int cur) {
        
        if (cur == word.size())
            return true;
        
        for (int i = max(x-1, 0); i < min(x+2, m); ++i) {
            if (word[cur] == b[i][y]) {
                b[i][y] = '-';
                if (recExists(b, word, i, y, cur+1))
                    return true;
                b[i][y] = word[cur];
            }
        }
        for (int i = max(y-1, 0); i < min(y+2, n); ++i) {
            if (word[cur] == b[x][i]) {
                b[x][i] = '-';
                if (recExists(b, word, x, i, cur+1))
                    return true;
                b[x][i] = word[cur];
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
