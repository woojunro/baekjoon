#include <iostream>

int main() {
    int N, r, c, zone, up, down, left, right, ret;
    
    std::cin >> N >> r >> c;
    
    up = 0;
    left = 0;
    down = 1;
    for (int i = 0; i < N; i++) {
        down *= 2;
    }
    right = 1;
    for (int i = 0; i < N; i++) {
        right *= 2;
    }
    
    ret = 0;
    for (int i = N - 1; i >= 0; i--) {
        zone = 0;
        
        if (r >= (up + down) / 2) {
            zone += 2;
            up = (up + down) / 2;
        } else {
            down = (up + down) / 2;
        }
        
        if (c >= (left + right) / 2) {
            zone += 1;
            left = (left + right) / 2;
        } else {
            right = (left + right) / 2;
        }
        
        for (int j = 0; j < i * 2; j++) {
            zone *= 2;
        }
        
        ret += zone;
    }
    
    std::cout << ret << std::endl;
    
    return 0;
}