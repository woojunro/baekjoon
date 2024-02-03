#include <iostream>

using namespace std;

int N, M, R;
int arr[300][300];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int min(int a, int b) {
    return a < b ? a : b;
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void rotate() {
    for (int start = 0; start < min(N, M) / 2; start++) {
        int x = start;
        int y = start;
        int dir = 0;
        int end_x = N - 1 - start;
        int end_y = M - 1 - start;

        int tmp = arr[x][y];
        while (dir < 4) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx >= start && nx <= end_x && ny >= start && ny <= end_y) {
                swap(tmp, arr[nx][ny]);
                x = nx;
                y = ny;
            } else {
                dir++;
            }
        }
    }
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int r = 0; r < R; r++) {
        rotate();
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}