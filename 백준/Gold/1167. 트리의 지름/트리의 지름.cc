#include <iostream>
#include <vector>
#include <stack>

#define MAX 100001

using namespace std;

vector<pair<int, int>> graph[MAX];
int dist[MAX];
stack<int> s;

pair<int, int> dfs(int start_node, int V) {
    for (int i = 1; i <= V; i++) dist[i] = -1;
    
    s.push(start_node);
    dist[start_node] = 0;
    
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int weight = graph[node][i].second;
            
            if (dist[next_node] == -1) {
                dist[next_node] = dist[node] + weight;
                s.push(next_node);
            }
        }
    }
    
    int max_node = 0;
    int max_dist = -1;
    
    for (int i = 1; i <= V; i++) {
        if (dist[i] > max_dist) {
            max_node = i;
            max_dist = dist[i];
        }
    }
    
    return make_pair(max_node, max_dist);
}

int main() {
    int V;
    cin >> V;
    
    for (int i = 0; i < V; i++) {
        int node;
        cin >> node;
        
        for (;;) {
            int next_node, weight;
            cin >> next_node;
            if (next_node == -1) break;
            
            cin >> weight;
            graph[node].push_back(make_pair(next_node, weight));
        }
    }
    
    pair<int, int> result = dfs(1, V);
    result = dfs(result.first, V);
    cout << result.second << endl;
    
    return 0;
}