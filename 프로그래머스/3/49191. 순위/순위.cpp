#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<int>> win_graph(n + 1);
    vector<vector<int>> lose_graph(n + 1);
    vector<int> in_degree(n + 1, 0);
    vector<int> out_degree(n + 1, 0);
    
    for (auto& result: results) {
        win_graph[result[0]].push_back(result[1]);
        lose_graph[result[1]].push_back(result[0]);
        in_degree[result[1]]++;
        out_degree[result[0]]++;
    }
    
    vector<unordered_set<int>> front_set(n + 1);
    queue<int> q;
    
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        for (auto nxt: win_graph[x]) {
            for (auto prev: front_set[x]) {
                front_set[nxt].insert(prev);
            }
            front_set[nxt].insert(x);
            in_degree[nxt]--;
            if (in_degree[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
    
    vector<unordered_set<int>> back_set(n + 1);
    
    for (int i = 1; i <= n; i++) {
        if (out_degree[i] == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        for (auto nxt: lose_graph[x]) {
            for (auto prev: back_set[x]) {
                back_set[nxt].insert(prev);
            }
            back_set[nxt].insert(x);
            out_degree[nxt]--;
            if (out_degree[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (front_set[i].size() + back_set[i].size() == n - 1) {
            ans++;
        }
    }
    return ans;
}