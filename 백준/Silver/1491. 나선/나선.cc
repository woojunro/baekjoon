#include <iostream>

using namespace std;

int N, M, i, j, direction;
bool palace[5000][5000];

bool move() {
    switch (direction) {
        case 0: // right
            if (j + 1 < N && !palace[i][j + 1]) {
                palace[i][++j] = true;
                return false;
            }
            if (i - 1 >= 0 && !palace[i - 1][j]) {
                direction = 1;
                return false;
            }
            return true;
        case 1: // up
            if (i - 1 >= 0 && !palace[i - 1][j]) {
                palace[--i][j] = true;
                return false;
            }
            if (j - 1 >= 0 && !palace[i][j - 1]) {
                direction = 2;
                return false;
            }
            return true;
        case 2: // left
            if (j - 1 >= 0 && !palace[i][j - 1]) {
                palace[i][--j] = true;
                return false;
            }
            if (i + 1 < M && !palace[i + 1][j]) {
                direction = 3;
                return false;
            }
            return true;
        default: // down
            if (i + 1 < M && !palace[i + 1][j]) {
                palace[++i][j] = true;
                return false;
            }
            if (j + 1 < N && !palace[i][j + 1]) {
                direction = 0;
                return false;
            }
            return true;
    }
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int r = 0; r < M; r++) {
        for (int c = 0; c < N; c++) {
            palace[r][c] = false;
        }
    }

    i = M - 1;
    j = 0;
    direction = 0;
    palace[i][j] = true;

    bool done = false;
    while (!done) {
        done = move();
    }

    cout << j << " " << (M - 1 - i);

    return 0;
}