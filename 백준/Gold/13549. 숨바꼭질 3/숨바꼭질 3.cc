#include <iostream>

#define MAX 100001

using namespace std;

int ETA[MAX + 1];

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int N, K;
    cin >> N >> K;
    
    for (int i = 0; i <= MAX; i++) ETA[i] = MAX;
    
    ETA[0] = N;
    for (int i = 1; i < MAX; i++) {
        if (i <= N) {
            ETA[i] = N - i;
        } else {
            if (i % 2 == 0) {
                ETA[i] = min(min(ETA[i - 1] + 1, ETA[i + 1] + 1), ETA[i / 2]);
            } else {
                ETA[i] = min(ETA[i - 1] + 1, ETA[i + 1] + 1);
            }
        }
        
        int teleport = 2 * i;
        while (teleport <= MAX) {
            ETA[teleport] = min(ETA[i], ETA[teleport]);
            teleport *= 2;
        }
    }
    
    cout << ETA[K] << endl;
    
    return 0;
}