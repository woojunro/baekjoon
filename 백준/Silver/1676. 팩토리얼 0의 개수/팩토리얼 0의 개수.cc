#include <iostream>

int main() {
    int N, five;
    std::cin >> N;
    
    five = 0;
    
    for (int i = 1; i <= N; i++) {
        int num = i;
        
        if (num % 5 == 0) {
            while (num % 5 == 0) {
                num /= 5;
                five++;
            }
        }
    }
    
    std::cout << five << std::endl;
        
    return 0;
}