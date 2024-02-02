#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int cards[10][3];
bool is_hab[10][10][10];
bool is_called[10][10][10];

bool is_all_same(int a, int b, int c) {
    return a == b && b == c;
}

bool is_all_different(int a, int b, int c) {
    return a != b && b != c && c != a;
}

void check_hab(int a, int b, int c) {
    bool valid = true;

    for (int i = 0; i < 3; i++) {
        if (!is_all_same(cards[a][i], cards[b][i], cards[c][i]) && !is_all_different(cards[a][i], cards[b][i], cards[c][i])) {
            valid = false;
            break;
        }
    }

    if (valid) {
        is_hab[a][b][c] = true;
    }
}

void combination(vector<int> &vec, int r) {
    vector<bool> is_selected(vec.size(), false);
    for (int i = 0; i < r; i++) {
        is_selected[i] = true;
    }

    do {
        vector<int> chosen;
        for (int i = 0; i < vec.size(); i++) {
            if (is_selected[i]) {
                chosen.push_back(vec[i]);
            }
        }
        check_hab(chosen[0], chosen[1], chosen[2]);
    } while (prev_permutation(is_selected.begin(), is_selected.end()));
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= 9; i++) {
        string s;

        // {“CIRCLE”, “TRIANGLE”, ”SQUARE”}
        cin >> s;
        if (s == "CIRCLE") {
            cards[i][0] = 0;
        }
        if (s == "TRIANGLE") {
            cards[i][0] = 1;
        }
        if (s == "SQUARE") {
            cards[i][0] = 2;
        }

        // {“YELLOW”, “RED”, “BLUE”}
        cin >> s;
        if (s == "YELLOW") {
            cards[i][1] = 0;
        }
        if (s == "RED") {
            cards[i][1] = 1;
        }
        if (s == "BLUE") {
            cards[i][1] = 2;
        }

        // {“GRAY”, “WHITE”, “BLACK”}
        cin >> s;
        if (s == "GRAY") {
            cards[i][2] = 0;
        }
        if (s == "WHITE") {
            cards[i][2] = 1;
        }
        if (s == "BLACK") {
            cards[i][2] = 2;
        }
    }

    vector<int> vec(9);
    for (int i = 0; i < 9; i++) {
        vec[i] = i + 1;
    }
    combination(vec, 3);

    int n;
    cin >> n;

    int score = 0;
    bool is_gyeol_called = false;

    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;

        if (c == 'H') {
            int arr[3];
            for (int a = 0; a < 3; a++) {
                cin >> arr[a];
            }
            sort(arr, arr + 3);

            if (is_hab[arr[0]][arr[1]][arr[2]] && !is_called[arr[0]][arr[1]][arr[2]]) {
                score++;
                is_called[arr[0]][arr[1]][arr[2]] = true;
            } else {
                score--;
            }
        } else {
            bool valid = true;

            for (int x = 1; x <= 9; x++) {
                for (int y = 1; y <= 9; y++) {
                    for (int z = 1; z <= 9; z++) {
                        if (is_hab[x][y][z] && !is_called[x][y][z]) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) {
                        break;
                    }
                }
                if (!valid) {
                    break;
                }
            }

            if (valid && !is_gyeol_called) {
                is_gyeol_called = true;
                score += 3;
            } else {
                score--;
            }
        }
    }

    cout << score;

    return 0;
}