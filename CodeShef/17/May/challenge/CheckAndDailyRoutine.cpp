#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main() {
    int N, i, curStat, curStatee;
    char str[100001];
    char states[] = {'C', 'E', 'S'};
    cin >> N;
    while(N--) {
        scanf("%s",str);
        curState = 0;
        for (i = 0; i < strlen(str); ++i) {
            int tState = curState;
            while (tState < 3) {
                if (str[i] == states[tState]) {
                    curState = tState;
                    break;
                }
                tState++;
            }
            if (tState == 3) {
                break;
            }
        }
        printf("%s\n", (i == strlen(str))?"yes":"no");
    }
    return 0;
}
