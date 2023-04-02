#include <iostream>
#include <string>

#define MAX 1001

int DP[MAX][MAX] = {0};

int main() {
    std::string A, B;
    std::getline(std::cin, A);
    std::getline(std::cin, B);
    
    for (int i = 1; i <= A.length(); i++) {
        for (int j = 1; j <= B.length(); j++) {
            if (A[i - 1] == B[j - 1]) {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            } else {
                DP[i][j] = DP[i - 1][j] > DP[i][j - 1] ? DP[i - 1][j] : DP[i][j - 1];
            }
        }
    }
    
    std::cout << DP[A.length()][B.length()] << "\n";
    
    return 0;
}