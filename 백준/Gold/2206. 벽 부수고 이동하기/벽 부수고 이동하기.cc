#include <iostream>
#include <string>
#include <queue>
#include <tuple>

#define MAX 1000

using namespace std;

bool MAP[MAX][MAX];
int dist[MAX][MAX][2];
queue<tuple<int, int, bool>> q;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool valid_coord(int x, int y, int N, int M) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int bfs(int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 2; k++) dist[i][j][k] = -1;
        }
    }
    
    dist[0][0][0] = 1;
    q.push(make_tuple(0, 0, false));
    
    while (!q.empty()) {
        int x, y;
        bool broken;
        tie(x, y, broken) = q.front();
        q.pop();
        
        if (x == N - 1 && y == M - 1) return dist[N - 1][M - 1][broken];
        
        for (int i = 0; i < 4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            
            if (!valid_coord(next_x, next_y, N, M)) continue;
            
            if (MAP[next_x][next_y] && dist[next_x][next_y][broken] == -1) {
                dist[next_x][next_y][broken] = dist[x][y][broken] + 1;
                q.push(make_tuple(next_x, next_y, broken));
            }
            
            if (!MAP[next_x][next_y] && !broken) {
                dist[next_x][next_y][1] = dist[x][y][0] + 1;
                q.push(make_tuple(next_x, next_y, true));
            }
        }
    }
    
    return -1;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        string row;
        getline(cin >> ws, row);
        
        for (int j = 0; j < M; j++) MAP[i][j] = row[j] == '0';
    }
    
    cout << bfs(N, M) << endl;
    
    return 0;
}