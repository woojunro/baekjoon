#include <iostream>
#include <vector>

using namespace std;

#define MAX 100
#define INF 999999999

int dist[MAX + 1][MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = (i == j ? 0 : INF);
        }
    }
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        if (c < dist[a][b]) dist[a][b] = c;
    }
    
    // Floyd-Warshall Algorithm
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                // j -> i -> k
                if (dist[j][i] + dist[i][k] < dist[j][k]) {
                    dist[j][k] = dist[j][i] + dist[i][k];
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << (dist[i][j] == INF ? 0 : dist[i][j]) << " ";
        }
        cout << "\n";
    }
    
    return 0;
}