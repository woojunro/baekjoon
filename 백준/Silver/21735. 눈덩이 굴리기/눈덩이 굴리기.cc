#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[1000001];
int ans = 0;

void doit(int cur, int pos, int depth) {
    if (pos == N || depth == M) {
        if (cur > ans) {
            ans = cur;
        }
        return;
    }

    doit(cur + arr[pos + 1], pos + 1, depth + 1);
    if (pos + 2 <= N) {
        doit(cur / 2 + arr[pos + 2], pos + 2, depth + 1);
    }
}

void solve() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    doit(1, 0, 0);

    cout << ans;
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}