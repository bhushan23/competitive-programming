#include <iostream>
#include <vector>
using namespace std;


void print(vector<int> lis) {
    for (int each : lis) {
        cout << each << " ";
    }
    cout << endl;
}
int main() {
    vector<int> test;
    int n = 5;
    for (int i = 0; i < 5; ++i) {
        test.push_back(i+1);
    }

    vector<vector<int> > set;
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> subset;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                subset.push_back( test[j]);
            }
        }
        set.push_back(subset);
    }

    for (auto each : set) {
        print(each);
    }
    return 0;
}
