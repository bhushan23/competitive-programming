#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int main() {
    int T, a, b;
    bool BobWin;
    vector<int> aVal(1001, -1), bVal(1001, -1);
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d", &a, &b);
        BobWin = false;
        if (aVal[a] != -1 && bVal[b] != -1) {
            if (aVal[a] < bVal[b]) {
                BobWin = true;
            }
        } else {
            int i = 1;
            int tA = a;
            int tB = b;
            while (tA >= 0 && tB >= 0) {
                if (i % 2) {
                        tA -= i;
                        if (tA < 0) {
                            BobWin = true;
                            aVal[a] = i;
                            break;
                        }
                } else {
                        tB -= i;
                        if (tB < 0) {
                            bVal[b] = i;
                            break;
                        }

                }
                i++;
            }

        }   
        printf("%s\n", BobWin?"Bob":"Limak");
    }
return 0;
}
