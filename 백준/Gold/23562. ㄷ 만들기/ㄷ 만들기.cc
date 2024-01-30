#include <iostream>

using namespace std;

int n, m, a, b;
int ans = 1e9;
char board[20][20], filter[20][20];

int min(int x, int y) {
    return x < y ? x : y;
}

void init_filter(int i, int j, int k) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            filter[r][c] = '.';
        }
    }

    for (int r = 0; r < k * 3; r++) {
        for (int c = 0; c < k * 3; c++) {
            filter[i + r][j + c] = '#';
        }
    }

    for (int r = k; r < k * 2; r++) {
        for (int c = k; c < k * 3; c++) {
            filter[i + r][j + c] = '.';
        }
    }
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> a >> b;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int max_k = min(n, m) / 3;

    for (int k = 1; k <= max_k; k++) {
        for (int i = 0; i <= n - k * 3; i++) {
            for (int j = 0; j <= m - k * 3; j++) {
                init_filter(i, j, k);
                int cost = 0;
                for (int r = 0; r < n; r++) {
                    for (int c = 0; c < m; c++) {
                        if (board[r][c] != filter[r][c]) {
                            if (board[r][c] == '.') {
                                cost += a;
                            } else {
                                cost += b;
                            }
                        }
                    }
                }
                if (cost < ans) {
                    ans = cost;
                }
            }
        }
    }

    cout << ans;

    return 0;
}