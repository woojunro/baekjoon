#include <iostream>
#include <set>

std::multiset<int> q;

int main() {
    int T, k, num;
    char command;
    std::multiset<int>::iterator iter;
    
    std::cin >> T;
    
    for (int i = 0; i < T; i++) {
        q.erase(q.begin(), q.end());
        std::cin >> k;
        
        for (int j = 0; j < k; j++) {
            std::cin >> command;
            
            if (command == 'I') {
                std::cin >> num;
                q.insert(num);
            } else { // D
                std::cin >> num;
                
                if (q.empty()) {
                    continue;
                }
                
                
                if (num == -1) {
                    q.erase(q.begin());
                } else { // -1
                    iter = q.end();
                    iter--;
                    q.erase(iter);
                }
            }
        }
        
        if (q.empty()) {
            std::cout << "EMPTY" << "\n";
        } else {
            iter = q.end();
            iter--;
            std::cout << *iter << " " << *q.begin() << "\n";
        }
    }
    
    return 0;
}