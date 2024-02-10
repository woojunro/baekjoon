#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>> tree(n + 1);
    for (vector<int> wire: wires) {
        tree[wire[0]].push_back(wire[1]);
        tree[wire[1]].push_back(wire[0]);
    }
    
    int answer = 100;
    
    for (vector<int> wire: wires) {
        int cnt = 0;
        queue<int> q;
        q.push(1);
        vector<bool> visited(n + 1, false);
        visited[1] = true;
        
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            cnt++;
            
            for (int nx: tree[x]) {
                if (visited[nx]) {
                    continue;
                }
                
                if ((x == wire[0] && nx == wire[1]) || (x == wire[1] && nx == wire[0])) {
                    continue;
                }
                
                visited[nx] = true;
                q.push(nx);
            }
        }
        
        int diff = n - cnt - cnt;
        if (diff < 0) diff *= -1;
        if (diff < answer) answer = diff;
    }
    
    return answer;
}