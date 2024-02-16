#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, X[50], Y[50];
int ans = 987654321;

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

        int max_dist = 0;

        for (int i = 0; i < N; i++) {
            int min_dist = 987654321;
            for (int c: chosen) {
                int dist = abs(X[i] - X[c]) + abs(Y[i] - Y[c]);
                if (dist < min_dist) {
                    min_dist = dist;
                }
            }

            if (min_dist > max_dist) {
                max_dist = min_dist;
            }
        }

        if (max_dist < ans) {
            ans = max_dist;
        }
    } while (prev_permutation(is_selected.begin(), is_selected.end()));
}

void solve() {
    cin >> N >> K;

    vector<int> vec;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        vec.push_back(i);
    }

    combination(vec, K);

    cout << ans;
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}