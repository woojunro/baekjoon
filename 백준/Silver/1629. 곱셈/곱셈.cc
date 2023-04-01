#include <iostream>

int A, B, C;

unsigned long long calculate(int y) {
    if (y == 1) {
        return A % C;
    }
    
    unsigned long long divide = calculate(y / 2);
    
    if (y % 2 == 0) {
        return (divide * divide) % C;
    } else {
        return (((divide * divide) % C) * A) % C;
    }
}

int main() {
    std::cin >> A >> B >> C;
    
    unsigned long long result = calculate(B);
    
    std::cout << result << std::endl;
    
    return 0;
}