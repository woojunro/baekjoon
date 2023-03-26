#include <iostream>

#define MAX 1000000000

int main() {
    int N, limit;
    std::cin >> N;
    
    limit = 1;
    for (int i = 1; i < MAX; i++) {
        if (N <= limit) {
            std::cout << i << std::endl;
            break;
        }
        
        limit += 6 * i;
    }
    
    return 0;
}