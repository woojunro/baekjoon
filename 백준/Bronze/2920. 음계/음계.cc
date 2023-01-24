#include <iostream>

int main() {
    int s;
    bool is_ascending = false;
    
    std::cin >> s;
    if (s == 1) {
        is_ascending = true;
    } else {
        if (s != 8) {
            std::cout << "mixed" << std::endl;
            return 0;
        }
    }
    
    for (int i = 0; i < 7; i++) {
        std::cin >> s;
        
        if (is_ascending) {
            if (s != i + 2) {
                std::cout << "mixed" << std::endl;
                return 0;
            }
        } else {
            if (s != 7 - i) {
                std::cout << "mixed" << std::endl;
                return 0;
            }
        }
    }
    
    std::cout << (is_ascending ? "ascending" : "descending") << std::endl;
    
    return 0;
}