#include <iostream>

using namespace std;

char board[20][20];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    bool valid = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num_cnt, mine_cnt;
            num_cnt = mine_cnt = 0;
            for (int r = (i - 1 >= 0 ? i - 1 : i); r <= (i + 1 < n ? i + 1 : i); r++) {
                for (int c = (j - 1 >= 0 ? j - 1 : j); c <= (j + 1 < m ? j + 1 : j); c++) {
                    if (board[r][c] == 'F') {
                        mine_cnt++;
                    } else {
                        num_cnt++;
                    }
                }
            }
            if ((board[i][j] == 'F' && num_cnt < 1) || (board[i][j] != 'F' && mine_cnt != board[i][j] - '0')) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            break;
        }
    }

    if (valid) {
        cout << "Well done Clark!\n";
    } else {
        cout << "Please sweep the mine again!\n";
    }
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        solve();
    }

    return 0;
}