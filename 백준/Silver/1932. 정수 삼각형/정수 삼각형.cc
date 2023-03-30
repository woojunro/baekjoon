#include <iostream>

int DP[500][500];

int main() {
    int n, num, max;
    std::cin >> n;
    
    std::cin >> DP[0][0];
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            std::cin >> num;
            max = 0;
            
            if (j - 1 >= 0) {
                max = DP[i - 1][j - 1];
            }
            
            if (j <= i) {
                max = DP[i - 1][j] > max ? DP[i - 1][j] : max;
            }
            
            DP[i][j] = max + num;
        }
    }
    
    max = 0;
    
    for (int i = 0; i < n; i++) {
        max = DP[n - 1][i] > max ? DP[n - 1][i] : max;
    }
    
    std::cout << max << std::endl;
    
    return 0;
}