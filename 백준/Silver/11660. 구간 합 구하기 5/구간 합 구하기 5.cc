#include <iostream>

int DP[1025][1025];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int N, M;
    std::cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int num;
            std::cin >> num;
            
            if (i > 1) {
                num += DP[i - 1][j];
            }
            
            if (j > 1) {
                num += DP[i][j - 1];
            }
            
            if (i > 1 && j > 1) {
                num -= DP[i - 1][j - 1];
            }
            
            DP[i][j] = num;
        }
    }
    
    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2, result;
        std::cin >> x1 >> y1 >> x2 >> y2;
        
        result = DP[x2][y2];
        
        if (x1 > 1) {
            result -= DP[x1 - 1][y2];
        }
        
        if (y1 > 1) {
            result -= DP[x2][y1 - 1];
        }
        
        if (x1 > 1 && y1 > 1) {
            result += DP[x1 - 1][y1 - 1];
        }
        
        std::cout << result << "\n";
    }
    
    return 0;
}