#include <iostream>

using namespace std;

int n, m, Q, cnt;
bool green[1001][1001];

void work(int dy, int dx, int y, int x) {
    for (;;) {
        if (green[y][x]) {
            break;
        }

        green[y][x] = true;
        cnt--;

        if (y + dy < 1 || y + dy > n || x + dx < 1 || x + dx > m) {
            break;
        }

        y += dy;
        x += dx;
    }
}

void solve() {
    cin >> n >> m >> Q;
    cnt = n * m;

    for (int q = 0; q < Q; q++) {
        int query;
        cin >> query;

        if (query == 1) {
            int dy, dx, y, x;
            cin >> dy >> dx >> y >> x;
            work(dy, dx, y, x);
        }
        if (query == 2) {
            int y, x;
            cin >> y >> x;
            cout << (green[y][x] ? 1 : 0) << "\n";
        }
        if (query == 3) {
            cout << cnt << "\n";
        }
    }
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}