#include <iostream>

#define MAX 41

int ZERO[MAX];
int ONE[MAX];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    ZERO[0] = 1;
    ZERO[1] = 0;
    ONE[0] = 0;
    ONE[1] = 1;
    for (int i = 2; i < MAX; i++) {
        ZERO[i] = ZERO[i - 1] + ZERO[i - 2];
        ONE[i] = ONE[i - 1] + ONE[i - 2];
    }
    
    int T, num;
    
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        std::cin >> num;
        std::cout << ZERO[num] << " " << ONE[num] << "\n";
    }
    
    return 0;
}