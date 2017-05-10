#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main() {
    int n, i, curStat, curStatee;
    int t, diff, temp;
    int preq, main;
    cin >> t;
    while(t--) {
        scanf("%d",&n);
        preq = 0;
        main = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d",&temp);
            if (((temp - preq) < 1)) {
                main++;
            } else {
                temp -= preq;
                diff  = main - temp + 1; 
                preq += temp;
                main = main - temp + 1;
            }
        }
        printf("%d\n",main);
    }
    return 0;
}
