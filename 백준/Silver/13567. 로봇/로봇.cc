#include <iostream>

using namespace std;

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    int i, j, direction;
    i = j = direction = 0;

    for (int n = 0; n < N; n++) {
        char c, dummy;
        cin >> c;
        for (int d = 0; d < 3; d++) {
            cin >> dummy;
        }

        int d;
        cin >> d;

        if (c == 'M') {
            switch (direction) {
                case 0:
                    i += d;
                    break;
                case 1:
                    j += d;
                    break;
                case 2:
                    i -= d;
                    break;
                default:
                    j -= d;
            }
            if (i < 0 || i > M || j < 0 || j > M) {
                cout << -1;
                return 0;
            }
        } else {
            if (d == 0) {
                direction = (direction + 1) % 4;
            } else {
                direction--;
                if (direction < 0) {
                    direction = 3;
                }
            }
        }
    }

    cout << i << " " << j;

    return 0;
}