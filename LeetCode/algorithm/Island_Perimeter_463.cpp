class Solution {
public:
    
    vector<vector<bool>> visited;
    int m, n;
    int Peri;
    
    void findPerimeter(vector<vector<int>> &grid, int x, int y) {
        if (visited[x][y])
            return;
        visited[x][y] = true;
        for (int i = max(x-1, 0); i < min(x+2,m); ++i) {
            if (i == x)
                continue;
            if (grid[i][y] == 0) {
                Peri++;
            } else if (!visited[i][y]){
                findPerimeter(grid, i, y);
            }
        }
        if (x == 0)
            Peri++;
        if (x == m-1)
            Peri++;
        for (int i = max(y-1, 0); i < min(y+2,n); ++i) {
            if (i == y)
                continue;
            if (grid[x][i] == 0) {
                Peri++;
            } else if (!visited[x][i]) {
                findPerimeter(grid, x, i);
            }
        }
        if (y == 0)
            Peri++;
        if (y == n-1)
            Peri++;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = m > 0 ? grid[0].size() : 0;
        
        visited.resize(m);
        for (int i = 0; i < m; ++i) {
            visited[i].resize(grid[0].size(), false);
        }
        Peri = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    findPerimeter(grid, i, j);
                    return Peri;
                }
            }
        }
        return 0;
    }
};
