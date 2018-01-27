class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> bMap;
        for (int i = 0; i < B.size(); ++i) {
            bMap[B[i]] = i;
        }
        vector<int> out(B.size(), 0);
        for (int i = 0; i < A.size(); ++i) {
            out[i] = bMap[A[i]];
        }
        return out;
    }
};
