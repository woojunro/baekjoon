#include <iostream>

using namespace std;

int n;
int box[26][4], puzzle[5][5][2];
bool is_used[26];
bool is_finished = false;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void print_puzzle() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << puzzle[i][j][0] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << puzzle[i][j][1] << " ";
        }
        cout << "\n";
    }
}

bool in_range(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void solve(int r) {
    if (is_finished) {
        return;
    }

    if (r == n * n) {
        print_puzzle();
        is_finished = true;
        return;
    }

    int x = r / n;
    int y = r % n;

    for (int i = 1; i <= n * n; i++) {
        if (is_used[i]) {
            continue;
        }

        int values[4];

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (in_range(nx, ny)) {
                int box_num = puzzle[nx][ny][0];
                int rotate_cnt = puzzle[nx][ny][1];
                if (box_num > 0) {
                    values[dir] = box[box_num][(dir + rotate_cnt * 3 + 2) % 4];
                } else {
                    values[dir] = -1;
                }
            } else {
                values[dir] = 0;
            }
        }

        for (int dir = 0; dir < 4; dir++) {
            bool valid = true;
            for (int j = 0; j < 4; j++) {
                if (values[j] == -1) {
                    continue;
                }

                if (box[i][(j + dir * 3) % 4] != values[j]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                puzzle[x][y][0] = i;
                puzzle[x][y][1] = dir;
                is_used[i] = true;

                solve(r + 1);
                if (is_finished) {
                    return;
                }

                puzzle[x][y][0] = 0;
                is_used[i] = false;
            }
        }
    }
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n * n; i++) {
        int num;
        cin >> num;

        for (int j = 0; j < 4; j++) {
            cin >> box[num][j];
        }
    }

    solve(0);

    return 0;
}