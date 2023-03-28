#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int M;
    std::cin >> M;
    
    bool set[21] = {0};
    
    for (int i = 0; i < M; i++) {
        std::string command;
        int num;
        
        std::cin >> command;
        
        if (command == "add") {
            std::cin >> num;
            set[num] = true;
        } else if (command == "remove") {
            std::cin >> num;
            set[num] = false;
        } else if (command == "check") {
            std::cin >> num;
            std::cout << (set[num] ? 1 : 0) << "\n";
        } else if (command == "toggle") {
            std::cin >> num;
            set[num] = set[num] ? false : true;
        } else if (command == "all") {
            for (int j = 1; j <= 20; j++) {
                set[j] = true;
            }
        } else if (command == "empty") {
            for (int j = 1; j <= 20; j++) {
                set[j] = false;
            }
        }
    }
    
    return 0;
}