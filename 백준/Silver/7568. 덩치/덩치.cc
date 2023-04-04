#include <iostream>

int main() {
    int weight[50], height[50];
    int N, rank;
    
    std::cin >> N;
    
    for (int i = 0; i < N; i++) {
        std::cin >> weight[i];
        std::cin >> height[i];
    }
    
    for (int i = 0; i < N; i++) {
        rank = 1;
        
        for (int j = 0; j < N; j++) {
            if (weight[i] < weight[j] && height[i] < height[j]) {
                rank++;
            }
        }
        
        std::cout << rank << " ";
    }
    
    return 0;
}