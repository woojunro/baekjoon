#include <iostream>

using namespace std;

int N, M, R;
int arr[300][300];

int min(int a, int b) {
    return a < b ? a : b;
}

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void rotate(int i) {
    int x = i;
    int y = i;
    int dir = 0;
    int end_x = N - i - 1;
    int end_y = M - i - 1;

    int val = arr[x][y];
    while (dir < 4) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx >= i && nx <= end_x && ny >= i && ny <= end_y) {
            arr[x][y] = arr[nx][ny];
            x = nx;
            y = ny;
        } else {
            dir++;
        }
    }

    arr[i + 1][i] = val;
}

void solve() {
    cin >> N >> M >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < min(N, M) / 2; i++) {
        for (int r = 0; r < R % ((N + M - i * 4) * 2 - 4); r++) {
            rotate(i);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}