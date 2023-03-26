#include <iostream>

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int x, y, w, h, min_value;
    std::cin >> x >> y >> w >> h;
    
    min_value = x;
    min_value = min(min_value, w - x);
    min_value = min(min_value, y);
    min_value = min(min_value, h - y);
    
    std::cout << min_value << std::endl;
    
    return 0;
}