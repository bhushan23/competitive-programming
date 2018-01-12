#define VALID(i, j) (i >= 0 && i < board.size() && j >= 0 && j < board[0].size())
class Solution {
public:
    vector<vector<int>> nBoard;
    int m;
    int n;
    int updateBoard(vector<vector<int>> board, int i, int j) {
        int liveCount = 0;
        
        for (int k = max(i-1, 0); k < min(i+2, m); ++k) {
            for (int l = max(j-1, 0); l < min(j+2, n); ++l) {
                if (k == i && l == j)
                    continue;
                if (board[k][l] & 0x1)
                    liveCount++;
            }   
        }

        if (liveCount < 2)
            return 0;
        if (liveCount > 3)
            return 0;
        if (board[i][j] == 0 && liveCount == 3)
            return 1;
        return board[i][j];
    }
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = (m > 0 ? board[0].size() : 0);
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                board[i][j] |= (updateBoard(board, i, j) << 3);
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                board[i][j] = board[i][j] >> 3;
            }
        }
    }
};
