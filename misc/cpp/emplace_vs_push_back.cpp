#include <iostream>
#include <vector>
using namespace std;

class test{
public:
        int var;

        test() {
                var = -1;
        }

        test(int v) {
                var = v;
        }
        test(int a, int b) {
                var = a+b;
        }
};


int main() {
    vector<test> vTest;
    // vTest.push_back({1, 2});
    vTest.emplace_back(1,2);
    cout << vTest[0].var << endl;
    return 0;
}
