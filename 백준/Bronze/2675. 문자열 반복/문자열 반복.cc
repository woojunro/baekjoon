#include <iostream>
#include <string>

int main() {
    int T, R;
    std::string S;
    
    std::cin >> T;
    
    for (int i = 0; i < T; i++) {
        std::cin >> R;
        std::getline(std::cin, S);
        
        for (int j = 1; j < S.size(); j++) {
            for (int k = 0; k < R; k++) {
                std::cout << S.at(j);
            }
        }
        std::cout << std::endl;
    }
    
    return 0;
}