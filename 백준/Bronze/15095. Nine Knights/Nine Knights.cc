#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> knight_row, knight_col;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            char c;
            cin >> c;
            if (c == 'k') {
                knight_row.push_back(i);
                knight_col.push_back(j);
            }
        }
    }

    if (knight_row.size() != 9) {
        cout << "invalid";
        return 0;
    }

    for (int i = 0; i < knight_row.size(); i++) {
        for (int j = i + 1; j < knight_row.size(); j++) {
            int row_diff = abs(knight_row[i] - knight_row[j]);
            int col_diff = abs(knight_col[i] - knight_col[j]);

            if ((row_diff == 2 && col_diff == 1) || (row_diff == 1 && col_diff == 2)) {
                cout << "invalid";
                return 0;
            }
        }
    }

    cout << "valid";

    return 0;
}