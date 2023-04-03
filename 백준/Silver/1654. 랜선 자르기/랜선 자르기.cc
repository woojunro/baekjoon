#include <iostream>

int lan[10000];

int main() {
    int K, N, max_length;
    long long low, mid, high;
    std::cin >> K >> N;
    
    max_length = 0;
    for (int i = 0; i < K; i++) {
        std::cin >> lan[i];
        if (lan[i] > max_length) {
            max_length = lan[i];
        }
    }
    
    // Binary Search
    low = 1;
    high = max_length;
    while (low <= high) {
        mid = (low + high) / 2;
        long long count = 0;
        
        for (int i = 0; i < K; i++) {
            count += lan[i] / mid;
        }
        
        if (count >= N) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    std::cout << --low << std::endl;
    
    return 0;
}