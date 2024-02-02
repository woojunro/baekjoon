#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combination(vector<int> &vec, int r) {
    vector<bool> is_selected(vec.size(), false);
    for (int i = 0; i < r; i++) {
        is_selected[i] = true;
    }

    do {
        vector<int> chosen;
        for (int i = 0; i < vec.size(); i++) {
            if (!is_selected[i]) {
                chosen.push_back(vec[i]);
            }
        }

        int total = 0;
        for (int i: chosen) total += i;
        if (total == 100) {
            for (int i: chosen) cout << i << "\n";
            exit(0);
        }
    } while (prev_permutation(is_selected.begin(), is_selected.end()));
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> vec;
    for (int i = 0; i < 9; i++) {
        int a;
        cin >> a;
        vec.push_back(a);
    }

    combination(vec, 2);

    return 0;
}