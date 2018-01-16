// Example program
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:

    void print(string s, int c) {
        for (int i = 0; i < s.length(); ++i) {
            if (i == c) {
                cout << "(" << s[i] << ") ";
            } else {
                cout << s[i] << " ";    
            }
            
        }
        cout << endl;
    }
    int repeatedStringMatch(string A, string B) {
        vector<int> pTable(B.length()+1, 0);
        int i = 0;
        int j = -1;
        int n = A.length();
        int m = B.length();
        pTable[0] = -1;
        while (i < m) {
            while (j >= 0 && B[i] != B[j])
                j = pTable[j];
            i++;
            j++;
            pTable[i] = j; 
        }

        i = 0;
        j = 0;
        pTable[0] = 0;
        for (auto k : pTable) {
            cout << k << " ";
        }
        cout << "\n";
        while (i < n) {
            j = pTable[i];
            print(A, i+j);
            print(B, j);
            cout << endl;
            while (j < m && A[(i+j)%n] == B[j]) {               
                print(A, i+j);
                print(B, j);
                cout << endl;
                ++j;
            }
            if (j == m)
                return i; // ((i+j)/n + ((i+j)%n != 0 ? 1: 0));
            i += max(1, j - pTable[j]);
        }
        return -1; 
    }
};

int main()
{
    Solution sol;
    string A="abaabababadeabadab";
    string B="abadab";
    cout << "\n At Index: " << sol.repeatedStringMatch(A, B);
}

