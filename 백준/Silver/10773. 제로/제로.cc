#include <iostream>
#include <stack>

std::stack<int> s;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int K, num;
    std::cin >> K;
    
    for (int i = 0; i < K; i++) {
        std::cin >> num;
        if (num == 0) {
            s.pop();
        } else {
            s.push(num);
        }
    }
    
    num = 0;
    while (!s.empty()) {
        num += s.top();
        s.pop();
    }
    
    std::cout << num << "\n";
    
    return 0;
}