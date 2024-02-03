#include <iostream>
#include <vector>

#define MAX 987654321

using namespace std;

int N;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool in_bound(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

vector<vector<int>> move(vector<vector<int>>& board, int idx) {
    bool down = dx[idx] == 1;
    bool right = dy[idx] == 1;
    vector<vector<int>> ret(N, vector<int>(N, 0));
    
    for (int i = down ? N - 1 : 0; in_bound(i, 0); i += down ? -1 : 1) {
        for (int j = right ? N - 1 : 0; in_bound(0, j); j += right ? -1 : 1) {
            if (board[i][j] == 0) continue;
            
            int n_i = i;
            int n_j = j;
            
            while (in_bound(n_i + dx[idx], n_j + dy[idx]) &&
                   ret[n_i + dx[idx]][n_j + dy[idx]] == 0) {
                n_i += dx[idx];
                n_j += dy[idx];
            }
            
            if (in_bound(n_i + dx[idx], n_j + dy[idx]) &&
                ret[n_i + dx[idx]][n_j + dy[idx]] == board[i][j]) {
                ret[n_i + dx[idx]][n_j + dy[idx]] *= -2;
            } else {
                ret[n_i][n_j] = board[i][j];
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (ret[i][j] < 0) ret[i][j] *= -1;
        }
    }
    
    return ret;
}

int max_value(vector<vector<int>> board, int move_count) {
    int ret = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] > ret) ret = board[i][j];
        }
    }
    
    if (move_count >= 5) return ret;
    
    for (int i = 0; i < 4; i++) {
        vector<vector<int>> n_board = move(board, i);
        int n_ret = max_value(n_board, move_count + 1);
        if (n_ret > ret) ret = n_ret;
    }
    
    return ret;
}

int main() {
    cin >> N;
    
    vector<vector<int>> board(N, vector<int>(N));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> board[i][j];
    }
    
    cout << max_value(board, 0);
    
    return 0;
}