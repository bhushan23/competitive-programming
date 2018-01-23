class Solution {
public:

    int minSteps(int n) {
        vector<int> ar(n+1, INT_MAX);
        ar[0] = ar[1] = 0;
        for (int i = 2; i <= n; ++i) {
            if (ar[i] == INT_MAX) {
                ar[i] = i;
            }
            // cout << i << " " << i << " :";
            int k = ar[i]+2;
            if (i*2 <= n) {
                ar[i*2] = min(ar[i*2], k);
            }
            for (int j = 3; i*j <= n; ++j) {
                ar[i*j] = min(ar[i*j], ++k);
                //cout << i*j << " " << ar[i*j] << " ";
            }
            //cout << endl;
        }
        return ar[n];
    }
};
