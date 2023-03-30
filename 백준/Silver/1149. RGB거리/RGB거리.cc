#include <iostream>

int DP[1000][3];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int N, price, min;
    std::cin >> N;
    
    for (int i = 0; i < 3; i++) {
        std::cin >> DP[0][i];
    }
    
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> price;
            min = 1000 * 1000 + 1;
            
            for (int k = 0; k < 3; k++) {
                if (k == j) {
                    continue;
                }
                
                min = DP[i - 1][k] < min ? DP[i - 1][k] : min;
            }
            
            DP[i][j] = min + price;
        }
    }
    
    min = DP[N - 1][0];
    min = DP[N - 1][1] < min ? DP[N - 1][1] : min;
    min = DP[N - 1][2] < min ? DP[N - 1][2] : min;
    
    std::cout << min << std::endl;
    
    return 0;
}