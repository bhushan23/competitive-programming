class Solution {
public:
    
    void updateAll(vector<int> &m, int i, int n) {
        for (int j = i; j <= n; j++) {
            m[j] = (m[j] == -1 ? (j/i + j%i) : min(m[j], j/i + j%i));
            if (j != i)
                m[j] = min(m[j], m[i] + m[j-i]);
        }
    }
    int numSquares(int n) {
        vector<int> mem(n+1, -1);
        mem[1] = 1;
        mem[2] = 2;
        mem[3] = 3;
        int lastSq = 0;
        for (int i = 4; i <= n; ++i) {
            double srt = sqrt(i);
            if (i == pow(floor(srt), 2)) {
                updateAll(mem, i, n);
                lastSq = i;
            } 
        }
       return mem[n]; 
    }
};
