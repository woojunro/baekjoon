#include <iostream>

using namespace std;

int n;
char mine_board[10][10], open_board[10][10];

int count_adjacent_mines(int i, int j) {
    int cnt = 0;
    for (int r = (i - 1 >= 0 ? i - 1 : i); r <= (i + 1 < n ? i + 1 : i); r++) {
        for (int c = (j - 1 >= 0 ? j - 1 : j); c <= (j + 1 < n ? j + 1: j); c++) {
            if (mine_board[r][c] == '*') {
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mine_board[i][j];
        }
    }

    bool is_mine_opened = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> open_board[i][j];
            if (mine_board[i][j] == '*') {
                if (open_board[i][j] == 'x') {
                    is_mine_opened = true;
                }
                open_board[i][j] = '*';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (open_board[i][j] == '*' && is_mine_opened) {
                cout << "*";
            } else if (open_board[i][j] == 'x') {
                cout << count_adjacent_mines(i, j);
            } else {
                cout << ".";
            }
        }
        cout << "\n";
    }

    return 0;
}