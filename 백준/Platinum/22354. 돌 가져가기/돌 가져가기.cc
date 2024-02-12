#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N;
string S;
int A[300000];

void solve() {
    cin >> N;
    cin >> S;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> groups;
    bool side = true;
    int max_val = A[0];
    char current_color = S[0];
    for (int i = 1; i < N; i++) {
        if (S[i] != current_color) {
            if (side) {
                side = false;
            } else {
                groups.push_back(max_val);
            }
            max_val = A[i];
            current_color = S[i];
        }

        if (A[i] > max_val) {
            max_val = A[i];
        }
    }

    priority_queue<int> pq;

    for (int g: groups) {
        pq.push(g);
    }

    long ans = 0;
    int cnt = 0;

    while (!pq.empty() && cnt < (groups.size() + 1) / 2) {
        int a = pq.top();
        pq.pop();

        ans += a;
        cnt++;
    }

    cout << ans;
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}