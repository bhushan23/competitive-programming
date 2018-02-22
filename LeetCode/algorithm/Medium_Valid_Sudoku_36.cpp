class Solution {
public:
    vector<unordered_set<char>> row;
    vector<unordered_set<char>> col;
    vector<vector<unordered_set<char>>> cell; //(3, vector<unordered_set<char>>(3)); // (i/3)*2+(j/3)

    bool NotPresent(char el, int i, int j) {
        if (row[i].find(el) != row[i].end())
            return false;
        if (col[j].find(el) != col[j].end())
            return false;
        if (cell[i/3][j/3].find(el) != cell[i/3][j/3].end())
            return false;
        return true;
    }
    void Add(char el, int i, int j) {
        row[i].insert(el);
        col[j].insert(el);
        cell[i/3][j/3].insert(el);
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = (m > 0 ? board[0].size() : 0);
        if (m == 0)
            return false;

        row.resize(m);
        col.resize(n);
        cell.resize(m);
        for (int i = 0; i < m/3; ++i)
            cell[i].resize(n/3);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] != '.' && !NotPresent(board[i][j], i, j)) {
                    return false;
                }
                if (board[i][j] != '.')
                    Add(board[i][j], i, j);
            }
        }
        return true;
    }
};
