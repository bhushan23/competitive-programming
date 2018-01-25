class Solution {
public:
    vector<int> uArray;
    vector<bool> isParent;

    int find(int i) {
        while (uArray[i] != i) {
            i = uArray[i];
        }
        return i;
    }

    void unify(int i, int j) {
        int a = find(i);
        int b = find(j);
        uArray[a] = b;
        isParent[b] = true;
        isParent[a] = false;
        // cout << a << " PAR of " << b << endl;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailMap;
        uArray.resize(accounts.size());
        isParent.resize(accounts.size(), false);
        for (int i = 0; i < accounts.size(); ++i) {
            uArray[i] = i;
        }

        for (int i = 0; i < accounts.size(); ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                if (emailMap.find(accounts[i][j]) == emailMap.end()) {
                    emailMap[accounts[i][j]] = i;
                } else {
                    int index = emailMap[accounts[i][j]];
                    if (i != index)
                        unify(i, index);
                }
            }
        }

        /*for (auto each : uArray) {
            cout << each << " ";
        }
        cout << endl;
        */
        unordered_map<int, set<string>> ans;
        unordered_map<int, string> names;
        for (int i = 0; i < accounts.size(); ++i) {
            // cout << i << " " << uArray[i] << " " << isParent[i] <<  endl;
            int parent = find(i);
            if (names.find(parent) == names.end()) {
                names[parent] = accounts[parent][0];

            }
            for (int j = 1; j < accounts[i].size(); ++j) {
                ans[parent].insert(accounts[i][j]);
            }
        }

        vector<vector<string>> finalAns(ans.size());
        for (int i = 0; i < ans.size(); ++i) {
            finalAns[i].push_back(names[i]);
            for (auto each : ans[i]) {
                finalAns[i].push_back(each);
            }
        }
        return finalAns;
    }
};
