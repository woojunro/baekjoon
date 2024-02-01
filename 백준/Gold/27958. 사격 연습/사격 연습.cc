#include <iostream>
#include <vector>

using namespace std;

int N, K, ans;
int board[8][8], score_board[8][8], current[8][8], bullet[5];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void init_board() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            current[i][j] = score_board[i][j] = board[i][j];
        }
    }
}

int calculateScore(vector<int> &perm) {
    init_board();

    int score = 0;

    for (int k = 0; k < K; k++) {
        int pos = perm[k];
        for (int j = 0; j < N; j++) {
            if (current[pos][j] >= 10) {
                score += current[pos][j];
                score_board[pos][j] = current[pos][j] = 0;
                break;
            }

            if (current[pos][j] > 0) {
                current[pos][j] -= bullet[k];
                if (current[pos][j] <= 0) {
                    int target_score = score_board[pos][j];
                    score += target_score;
                    score_board[pos][j] = current[pos][j] = 0;
                    for (int i = 0; i < 4; i++) {
                        int nx = pos + dx[i];
                        int ny = j + dy[i];
                        if (nx >= 0 && nx < N && ny >= 0 && ny < N && current[nx][ny] == 0) {
                            score_board[nx][ny] = current[nx][ny] = target_score >> 2;
                        }
                    }
                }
                break;
            }
        }
    }

    return score;
}

void permWithRep(vector<int> &vec, vector<int> &perm, int depth) {
    if (depth == perm.size()) {
        int score = calculateScore(perm);
        if (score > ans) {
            ans = score;
        }
        return;
    }

    for (int i: vec) {
        perm[depth] = i;
        permWithRep(vec, perm, depth + 1);
    }
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    for (int k = 0; k < K; k++) {
        cin >> bullet[k];
    }

    vector<int> vec(N), perm(K);
    for (int i = 0; i < N; i++) {
        vec[i] = i;
    }

    permWithRep(vec, perm, 0);

    cout << ans;

    return 0;
}