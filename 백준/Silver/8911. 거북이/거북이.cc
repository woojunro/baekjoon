#include <iostream>
#include <string>

using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        string s;
        getline(cin >> ws, s);

        int x, y, min_x, max_x, min_y, max_y, direction;
        x = y = min_x = max_x = min_y = max_y = direction = 0;

        for (char c: s) {
            switch (c) {
                case 'F':
                    switch (direction) {
                        case 0:
                            y++;
                            break;
                        case 1:
                            x--;
                            break;
                        case 2:
                            y--;
                            break;
                        default:
                            x++;
                    }
                    break;
                case 'B':
                    switch (direction) {
                        case 0:
                            y--;
                            break;
                        case 1:
                            x++;
                            break;
                        case 2:
                            y++;
                            break;
                        default:
                            x--;
                    }
                    break;
                case 'L':
                    direction = (direction + 1) % 4;
                    break;
                default:
                    direction--;
                    if (direction < 0) {
                        direction = 3;
                    }
            }

            min_x = min(min_x, x);
            max_x = max(max_x, x);
            min_y = min(min_y, y);
            max_y = max(max_y, y);
        }

        cout << (max_x - min_x) * (max_y - min_y) << endl;
    }

    return 0;
}