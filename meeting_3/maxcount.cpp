#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define MAX_A 10001

using namespace std;

int T, N, A;
int freqMap[MAX_A];

int main() {
    scanf("%d", &T);

    for(int i = 0; i < T; i++) {
        // set freqMap to 0
        memset(freqMap, 0, sizeof(int) * MAX_A);

        scanf("%d", &N);

        for(int j = 0; j < N; j++) {
            scanf("%d", &A);
            freqMap[A]++;
        }

        int maxElement = 1;
        for(int j = 1; j < MAX_A; j++) {
            if(freqMap[j] > freqMap[maxElement]) maxElement = j;
        }

        cout << maxElement << " " << freqMap[maxElement] << "\n";
    }

    return 0;
}
