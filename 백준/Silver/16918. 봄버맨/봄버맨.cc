#include <iostream>
#include <queue>

using namespace std;

int R, C, N;
int board[200][200];
queue<pair<int, int>> q;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void explode(int x, int y) {
    board[x][y] = -1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
            board[nx][ny] = -1;
        }
    }
}

void bomberman() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (++board[i][j] == 3) {
                q.emplace(i, j);
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        explode(x, y);
    }
}

void solve() {
    cin >> R >> C >> N;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char c;
            cin >> c;
            if (c == '.') {
                board[i][j] = -1;
            } else {
                board[i][j] = 1;
            }
        }
    }

    for (int n = 2; n <= N; n++) {
        bomberman();
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << (board[i][j] >= 0 ? 'O' : '.');
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