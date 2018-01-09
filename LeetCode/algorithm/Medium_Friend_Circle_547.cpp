class Solution {
public:
    vector<int> group;
    
    int find(int i) {
        while ( i < group.size() && group[i] != i) {
            i = group[i];
        }
        return i;
    }
    
    void unionGroups(int i, int j) {
        int pI = find(i);
        int pJ = find(j);
        group[pI] = pJ;
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int m = M.size();
        group.resize(m);
        
        for (int i = 0; i < m; ++i) {
            group[i] = i;
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < i; ++j) {
                if (M[i][j]) {
                    unionGroups(i, j);
                }
            }
        }
        int circles = 0;
        for (int i = 0; i < m; ++i) {
            if (group[i] == i)
                circles++;
        }
        return circles;
    }
};
