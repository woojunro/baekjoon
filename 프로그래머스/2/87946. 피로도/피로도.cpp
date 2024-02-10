#include <string>
#include <vector>

using namespace std;

int solve(vector<bool> &visited, int depth, int current, vector<vector<int>> &dungeons) {
    if (depth == dungeons.size()) {
        return depth;
    }
    
    int max_cnt = depth;
    
    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i] && current >= dungeons[i][0]) {
            visited[i] = true;
            int cnt = solve(visited, depth + 1, current - dungeons[i][1], dungeons);
            if (cnt > max_cnt) {
                max_cnt = cnt;
            }
            visited[i] = false;
        }
    }
    
    return max_cnt;
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visited(dungeons.size(), false);
    int answer = solve(visited, 0, k, dungeons);
    return answer;
}