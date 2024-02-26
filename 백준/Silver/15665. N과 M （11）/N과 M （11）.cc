#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N;
int arr[7];
vector<int> vec;

void doit(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < vec.size(); i++) {
        arr[depth] = vec[i];
        doit(depth + 1);
    }
}

void solve() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        vec.push_back(val);
    }

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    doit(0);
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}