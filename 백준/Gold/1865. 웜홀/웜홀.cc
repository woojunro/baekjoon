#include <iostream>
#include <vector>
#include <tuple>

#define INF 999999999

using namespace std;

void solve() {
    int N, M, W;
    cin >> N >> M >> W;
    
    vector<tuple<int, int, int>> edges;
    
    for (int i = 0; i < M; i++) {
        int S, E, T;
        cin >> S >> E >> T;
        
        edges.push_back(make_tuple(S, E, T));
        edges.push_back(make_tuple(E, S, T));
    }
    
    for (int i = 0; i < W; i++) {
        int S, E, T;
        cin >> S >> E >> T;
        
        edges.push_back(make_tuple(S, E, -1 * T));
    }
    
    vector<int> dist, predecessor;
    
    for (int i = 0; i <= N; i++) {
        dist.push_back(INF);
        predecessor.push_back(0);
    }
    
    dist[1] = 0;
    
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < edges.size(); j++) {
            int u, v, w;
            tie(u, v, w) = edges[j];
            
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                predecessor[v] = u;
            }
        }
    }
    
    // Check negative cycles
    bool negative_cycle = false;
    
    for (int i = 1; i <= N; i++) {
        int prev = predecessor[i];
        
        if (prev == 0) continue;
        
        for (int j = 0; j < edges.size(); j++) {
            int u, v, w;
            tie(u, v, w) = edges[j];
            
            if (prev == u && i == v && dist[i] > dist[u] + w) {
                negative_cycle = true;
                break;
            }
        }
        
        if (negative_cycle) break;
    }
    
    cout << (negative_cycle ? "YES" : "NO") << "\n";
}

int main() {
    int TC;
    cin >> TC;
    
    for (int i = 0; i < TC; i++) solve();
    
    return 0;
}