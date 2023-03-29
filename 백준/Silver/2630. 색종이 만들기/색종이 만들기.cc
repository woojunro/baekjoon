#include <iostream>

int paper[128][128];
int colors[2] = {0};

void divide(int up, int down, int left, int right) {
    int color = paper[up][left];
    bool same_color = true;
    
    for (int i = up; i < down; i++) {
        for (int j = left; j < right; j++) {
            if (paper[i][j] != color) {
                same_color = false;
                break;
            }
        }
        if (!same_color) {
            break;
        }
    }
    
    if (same_color) {
        colors[color]++;
    } else {
        divide(up, (up + down) / 2, left, (left + right) / 2);
        divide(up, (up + down) / 2, (left + right) / 2, right);
        divide((up + down) / 2, down, left, (left + right) / 2);
        divide((up + down) / 2, down, (left + right) / 2, right);
    }
}

int main() {
    int N;
    std::cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> paper[i][j];
        }
    }
    
    divide(0, N, 0, N);
    
    std::cout << colors[0] << "\n" << colors[1] << std::endl;
    
    return 0;
}