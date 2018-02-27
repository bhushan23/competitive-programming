class Solution {
public:
    vector<int> out;
    int Limit;
    void addRecLex(int n) {
        for (int i = 0; i < 10; ++i) {
            int newN = n*10 + i;
            if (newN > Limit) {
                return;
            }
            out.push_back(newN);
            addRecLex(newN);
        }
    }

    vector<int> lexicalOrder(int n) {
        Limit = n;
        for (int i = 1; i <= n && i < 10; ++i) {
            out.push_back(i);
            addRecLex(i);
        }
        return out;
    }
};
