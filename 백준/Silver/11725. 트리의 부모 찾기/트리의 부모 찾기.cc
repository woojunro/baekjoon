#include <iostream>
#include <vector>
#include <queue>

std::vector<int> adjacency[100001];
int parent[100001] = {0};
std::queue<int> q;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int N;
    std::cin >> N;
    
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        
        adjacency[a].push_back(b);
        adjacency[b].push_back(a);
    }
    
    parent[1] = -1;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        for (int i = 0; i < adjacency[x].size(); i++) {
            if (parent[adjacency[x][i]] == 0) {
                parent[adjacency[x][i]] = x;
                q.push(adjacency[x][i]);
            }
        }
    }
    
    for (int i = 2; i <= N; i++) {
        std::cout << parent[i] << "\n";
    }
    
    return 0;
}