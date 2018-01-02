class Solution {
public:
    int island; 
    bool landExists;
    int m, n;
    
    void dfsVisit(vector<vector<bool>> &visited, vector<vector<char>> &grid, int x, int y) {
        if (visited[x][y])
            return;
        visited[x][y] = true;
        if (grid[x][y] == '1') {
            landExists = true;
            for (int i = max(x-1, 0); i < min(x+2, m); i++)
                dfsVisit(visited, grid, i, y);
            for (int i = max(y-1, 0); i < min(y+2, n); i++)
                dfsVisit(visited, grid, x, i);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = m ? grid[0].size() : 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        island = 0;
        
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                landExists = false;
                if (visited[i][j] == false) {
                    dfsVisit(visited, grid, i, j);
                    cout << landExists;
                    count += (landExists ? 1: 0);
                }
            }
        }
        return count;
    }
};
