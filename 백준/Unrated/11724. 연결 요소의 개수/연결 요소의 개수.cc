#include <iostream>
#include <queue>

bool adjacency[1000][1000] = {0};
bool visited[1000] = {0};
std::queue<int> q;

int main() {
    int nodes, edges, count;
    std::cin >> nodes >> edges;
    
    for (int i = 0; i < edges; i++) {
        int x, y;
        std::cin >> x >> y;
        adjacency[x - 1][y - 1] = true;
        adjacency[y - 1][x - 1] = true;
    }
    
    count = 0;
    
    for (int i = 0; i < nodes; i++) {
        if (visited[i]) {
            continue;
        }
        
        q.push(i);
        visited[i] = true;
        
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            
            for (int j = 0; j < nodes; j++) {
                if (adjacency[x][j] && !visited[j]) {
                    q.push(j);
                    visited[j] = true;
                }
            }
        }
        
        count++;
    }
    
    std::cout << count << std::endl;
    
    return 0;
}