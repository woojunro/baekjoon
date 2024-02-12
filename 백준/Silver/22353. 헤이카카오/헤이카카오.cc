#include <iostream>

using namespace std;

void solve() {
    int a;
    double d, k;
    cin >> a >> d >> k;

    d /= 100;
    k /= 100;

    int cnt = 1;
    double ans = 0;
    double win_rate = d;
    double lose_rate = 1;

    for (;;) {
        if (win_rate >= 1) {
            ans += lose_rate * a * cnt;
            break;
        }

        ans += lose_rate * win_rate * a * cnt;
        lose_rate *= (1 - win_rate);
        win_rate *= (1 + k);
        cnt++;
    }

    cout << fixed;
    cout.precision(6);
    cout << ans;
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}