#include <iostream>
#include <queue>

int adjacency[101][101];
std::queue<int> q;

void infect(int x, int computers) {
    for (int i = 1; i <= computers; i++) {
        if (adjacency[i][x] == 1) {
            adjacency[i][x] = 2;
        }
    }
}

int main() {
    int computers, connections;
    std::cin >> computers >> connections;
    
    for (int i = 0; i < connections; i++) {
        int x, y;
        std::cin >> x >> y;
        adjacency[x][y] = 1;
        adjacency[y][x] = 1;
    }
    
    q.push(1);
    infect(1, computers);
    
    int count = 0;
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        for (int i = 1; i <= computers; i++) {
            if (adjacency[x][i] == 1) {
                q.push(i);
                infect(i, computers);
                count++;
            }
        }
    }
    
    std::cout << count << std::endl;
    
    return 0;
}