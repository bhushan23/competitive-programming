#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
int main() {
    int T, n;
    unsigned long long ans, k;
    char string[100001];
    scanf("%d",&T);
    while(T--) {
            scanf("%d %llu", &n, &k);
            scanf("%s", string);
            vector<int> numB;
            int cntB = 0;
            for (int i = strlen(string) - 1; i >= 0; i--) {
                if (string[i] == 'b') {
                    cntB++;
                } else if (string[i] == 'a') {
                    numB.push_back(cntB);
                }
            }
            ans = 0;
            unsigned long long kSum = (k) * (k+1) / 2;
            unsigned long long k1Sum = (k) * (k-1) / 2;

            for (int i = 0; i < numB.size(); ++i) {
                //for (int k1 = k; k1 > 0; --k1) {
                   ans += numB[i]*kSum;
                   ans += (cntB - numB[i]) * k1Sum;

                //}
            }
            printf("%llu\n",ans);

    }
    return 0;
}
