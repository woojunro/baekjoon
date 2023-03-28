#include <iostream>
#include <algorithm>

int main() {
    int queue[1000];
    int N;
    
    std::cin >> N;
    
    for (int i = 0; i < N; i++) {
        std::cin >> queue[i];
    }
    
    std::sort(queue, queue + N);
    
    int sum = 0;
    
    for (int i = 0; i < N; i++) {
        sum += queue[i] * (N - i);
    }
    
    std::cout << sum << std::endl;
    
    return 0;
}