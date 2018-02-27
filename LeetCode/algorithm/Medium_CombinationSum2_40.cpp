class Solution {
public:

    vector<vector<int>> out;

    void combSumRec(vector<int> &cand, int index, int target, vector<int> added) {
        if (target == 0) {
            out.push_back(added);
            return;
        }

        for (int i = index; i < cand.size(); ++i) {
            if (target - cand[i] < 0)
                continue;
            added.push_back(cand[i]);
            combSumRec(cand, i+1, target-cand[i], added);
            added.pop_back();

            while ((i < cand.size()-1 && cand[i] == cand[i+1]))
                i++;

        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        combSumRec(candidates, 0, target, {});
        return out;
    }

};


       
