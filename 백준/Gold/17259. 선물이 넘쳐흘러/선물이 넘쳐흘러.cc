#include <iostream>

using namespace std;

bool factory[100][100];
int B, N, M, ans, trash_cnt, m;
int staff_x[300], staff_y[300], speed[300], current[300];

int belt_dx[3] = {0, -1, 0};
int belt_dy[3] = {1, 0, -1};
int staff_dx[3] = {1, 0, -1};
int staff_dy[3] = {0, 1, 0};

void move_belt() {
    int x = B - 1;
    int y = 0;
    int dir = 0;

    if (factory[x][y]) {
        trash_cnt++;
    }

    while (dir < 3) {
        int nx = x + belt_dx[dir];
        int ny = y + belt_dy[dir];
        if (nx >= 0 && nx < B && ny >= 0 && ny < B) {
            factory[x][y] = factory[nx][ny];
            x = nx;
            y = ny;
        } else {
            dir++;
        }
    }

    if (m < M) {
        factory[0][0] = true;
        m++;
    } else {
        factory[0][0] = false;
    }
}

void handle_staffs() {
    for (int i = 0; i < N; i++) {
        if (current[i] >= 0 && ++current[i] == speed[i]) {
            ans++;
            current[i] = -1;
        }

        if (current[i] == -1) {
            for (int j = 0; j < 3; j++) {
                int x = staff_x[i] + staff_dx[j];
                int y = staff_y[i] + staff_dy[j];
                if (x >= 0 && x < B && y >= 0 && y < B && factory[x][y]) {
                    current[i] = 0;
                    factory[x][y] = false;
                    break;
                }
            }
        }
    }
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> B >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> staff_x[i] >> staff_y[i] >> speed[i];
        current[i] = -1;
    }

    ans = trash_cnt = m = 0;
    while (ans + trash_cnt < M) {
        move_belt();
        handle_staffs();
    }

    cout << ans;

    return 0;
}