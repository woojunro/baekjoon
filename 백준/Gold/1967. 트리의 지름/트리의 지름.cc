#include <iostream>
#include <vector>

#define MAX 10001

using namespace std;

vector<pair<int, int>> graph[MAX];
int dist[MAX];

void dfs(int node, int current_dist) {
    dist[node] = current_dist;
    
    for (int i = 0; i < graph[node].size(); i++) {
        int next_node = graph[node][i].first;
        int weight = graph[node][i].second;
        
        if (dist[next_node] < 0) {
            dfs(next_node, current_dist + weight);
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n - 1; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        
        graph[x].push_back(make_pair(y, w));
        graph[y].push_back(make_pair(x, w));
    }
    
    for (int i = 1; i <= n; i++) dist[i] = -1;
    dfs(1, 0);
    
    int farthest_node = 0;
    int max_dist = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > max_dist) {
            farthest_node = i;
            max_dist = dist[i];
        }
    }
    
    for (int i = 1; i <= n; i++) dist[i] = -1;
    dfs(farthest_node, 0);
    
    for (int i = 1; i <= n; i++) {
        if (dist[i] > max_dist) {
            max_dist = dist[i];
        }
    }
    
    cout << max_dist << endl;
    
    return 0;
}