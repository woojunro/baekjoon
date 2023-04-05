#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 20001
#define INF 99999999

using namespace std;

vector<pair<int, int>> graph[MAX];
int D[MAX];
bool updated[MAX] = {0};
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int V, E, K;
    cin >> V >> E >> K;
    
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        graph[u].push_back(make_pair(w, v));
    }
    
    for (int i = 1; i <= V; i++) {
        D[i] = INF;
    }
    
    D[K] = 0;
    pq.push(make_pair(0, K));
    
    while(!pq.empty()) {
        for (int i = 1; i <= V; i++) {
            updated[i] = false;
        }
        
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for (int i = 0; i < graph[node].size(); i++) {
            int w = graph[node][i].first;
            int v = graph[node][i].second;
            
            if (dist + w < D[v]) {
                D[v] = dist + w;
                updated[v] = true;
            }
        }
        
        for (int i = 1; i <= V; i++) {
            if (updated[i]) {
                pq.push(make_pair(D[i], i));
            }
        }
    }
    
    for (int i = 1; i <= V; i++) {
        if (D[i] == INF) {
            cout << "INF" << "\n";
        } else {
            cout << D[i] << "\n";   
        }
    }
    
    return 0;
}