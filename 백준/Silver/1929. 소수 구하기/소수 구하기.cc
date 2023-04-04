#include <iostream>
#include <cmath>

#define MAX 1000001

bool not_prime[MAX] = {0};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int M, N;
    std::cin >> M >> N;
    
    not_prime[1] = true;
    for (int i = 4; i <= N; i += 2) {
        not_prime[i] = true;
    }
    for (int i = 3; i <= std::sqrt(N); i += 2) {
        for (int j = 2; i * j <= N; j++) {
            not_prime[i * j] = true;
        }
    }
    
    for (int i = M; i <= N; i++) {
        if (!not_prime[i]) {
            std::cout << i << "\n";
        }
    }
    
    return 0;
}