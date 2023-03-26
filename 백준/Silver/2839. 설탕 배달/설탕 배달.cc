#include <iostream>

int main() {
    int N;
    std::cin >> N;
    
    int five = N / 5;
    
    for (int i = five; i >= 0; i--) {
        if ((N - i * 5) % 3 == 0) {
            std::cout << i + ((N - i * 5) / 3) << std::endl;
            return 0;
        }
    }
    
    std::cout << -1 << std::endl;
    return 0;
}