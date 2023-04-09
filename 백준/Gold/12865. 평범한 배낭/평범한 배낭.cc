#include <iostream>

#define MAX 100

using namespace std;

int DP [MAX + 1][100001] = {0};

int main() {
    int N, K;
    int V[MAX + 1], W[MAX + 1];
    
    cin >> N >> K;
    
    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i];
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            DP[i][j] = DP[i - 1][j];
            
            if (j - W[i] >= 0 && DP[i - 1][j - W[i]] + V[i] >= DP[i][j]) {
                DP[i][j] = DP[i - 1][j - W[i]] + V[i];
            }
        }
    }
    
    cout << DP[N][K] << endl;
    
    return 0;
}