#include <iostream>

using namespace std;

bool paper[100][100];

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int n = 0; n < N; n++) {
        int a, b;
        cin >> a >> b;

        for (int x = a; x < a + 10; x++) {
            for (int y = b; y < b + 10; y++) {
                paper[x][y] = true;
            }
        }
    }

    int ans = 0;
    for (int x = 0; x < 100; x++) {
        for (int y = 0; y < 100; y++) {
            if (paper[x][y]) {
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}