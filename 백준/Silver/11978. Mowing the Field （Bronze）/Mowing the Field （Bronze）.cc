#include <iostream>

#define MAX 987654321

using namespace std;

int farm[2001][2001];

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int x = 1000, y = 1000;
    for (int i = y - N * 10; i <= y + N * 10; i++) {
        for (int j = x - N * 10; j <= x + N * 10; j++) {
            farm[i][j] = -1;
        }
    }

    farm[x][y] = 0;
    int t = 0;
    int max_ans = MAX;

    for (int n = 0; n < N; n++) {
        char D;
        int S, dx, dy;
        cin >> D >> S;

        if (D == 'N') {
            dx = 0;
            dy = -1;
        } else if (D == 'E') {
            dx = 1;
            dy = 0;
        } else if (D == 'S') {
            dx = 0;
            dy = 1;
        } else { // W
            dx = -1;
            dy = 0;
        }

        for (int s = 0; s < S; s++) {
            t++;
            x += dx;
            y += dy;
            if (farm[x][y] == -1) {
                farm[x][y] = t;
            } else {
                int diff = t - farm[x][y];
                if (diff < max_ans) {
                    max_ans = diff;
                }
                farm[x][y] = t;
            }
        }
    }

    if (max_ans == MAX) {
        cout << -1;
    } else {
        cout << max_ans;
    }

    return 0;
}