#include <iostream>
#include <queue>

bool farm[50][50];
std::queue<int> queue_x;
std::queue<int> queue_y;

void bfs(int x, int y, int M, int N) {
    queue_x.push(x);
    queue_y.push(y);
    
    while (!queue_x.empty()) {
        int node_x = queue_x.front();
        int node_y = queue_y.front();
        
        queue_x.pop();
        queue_y.pop();
        
        // Up
        if (node_x > 0 && farm[node_x - 1][node_y]) {
            farm[node_x - 1][node_y] = false;
            queue_x.push(node_x - 1);
            queue_y.push(node_y);
        }
        
        // Down
        if (node_x < M - 1 && farm[node_x + 1][node_y]) {
            farm[node_x + 1][node_y] = false;
            queue_x.push(node_x + 1);
            queue_y.push(node_y);
        }
        
        // Left
        if (node_y > 0 && farm[node_x][node_y - 1]) {
            farm[node_x][node_y - 1] = false;
            queue_x.push(node_x);
            queue_y.push(node_y - 1);
        }
        
        // Right
        if (node_y < N - 1 && farm[node_x][node_y + 1]) {
            farm[node_x][node_y + 1] = false;
            queue_x.push(node_x);
            queue_y.push(node_y + 1);
        }
    }
}

int main() {
    int T, M, N, K, X, Y, count;
    
    std::cin >> T;
    for (int t = 0; t < T; t++) {
        std::cin >> M >> N >> K;
        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                farm[i][j] = false;
            }
        }
        
        for (int i = 0; i < K; i++) {
            std::cin >> X >> Y;
            farm[X][Y] = true;
        }
        
        count = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (farm[i][j]) {
                    count++;
                    farm[i][j] = false;
                    bfs(i, j, M, N);
                }
            }
        }
        
        std::cout << count << "\n";
    }
    
    return 0;
}