#include <iostream>

#define MAX_DIGITS 30

int DP[101][51][MAX_DIGITS] = {0};

void add(int *a, int *b, int *result) {
    for (int i = MAX_DIGITS - 1; i > 0; i--) {
        result[i] += a[i] + b[i];
        
        if (result[i] >= 10) {
            result[i - 1]++;
            result[i] -= 10;
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    
    if (m > n / 2) {
        m = n - m;
    }
    
    DP[0][0][MAX_DIGITS - 1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i && j <= m; j++) {
            if (j == 0 || j == i) {
                DP[i][j][MAX_DIGITS - 1] = 1;
            } else {
                add(DP[i - 1][j - 1], DP[i - 1][j], DP[i][j]);
            }
        }
    }
    
    int i = 0;
    while (DP[n][m][i] == 0) {
        i++;
    }
    while (i < MAX_DIGITS) {
        std::cout << DP[n][m][i];
        i++;
    }
    std::cout << std::endl;
    
    return 0;
}