#include <iostream>

using namespace std;

int N;
bool visited[30][30];
double ans = 0;

double prob[4];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void doit(int x, int y, double cur, int depth) {
    if (depth == N) {
        ans += cur;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!visited[nx][ny]) {
            visited[nx][ny] = true;
            doit(nx, ny, cur * prob[i], depth + 1);
            visited[nx][ny] = false;
        }
    }
}

void solve() {
    cin >> N;
    for (int i = 0; i < 4; i++) {
        cin >> prob[i];
        prob[i] /= 100;
    }

    visited[14][14] = true;
    doit(14, 14, 1, 0);

    cout << fixed;
    cout.precision(9);
    cout << ans;
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}