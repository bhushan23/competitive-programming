#define VALID(x, y) (x >= 0 && x < m && y >= 0 && y < n)
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = (m > 0 ? grid[0].size() : 0);
        int ans = -1;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int dir[] = {-1, 0, 1, 0, -1};
        pq.push({grid[0][0], 0, 0});
        while (!pq.empty()) {
            vector<int> el = pq.top();
            pq.pop();

            ans = max(ans, el[0]);

            for (int i = 0; i < 4; i++) {
                int nR = el[1] + dir[i];
                int nC = el[2] + dir[i+1];
                if (VALID(nR, nC) && visited[nR][nC] == false) {
                    if (nC == m-1 && nR == n-1) {
                        return max(ans, grid[nC][nR]);
                    }
                    pq.push({grid[nR][nC], nR, nC});
                    visited[nR][nC] = true;
                }
            }

        }
        return -1;
    }
};
