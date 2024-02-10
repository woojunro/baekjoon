#include <string>
#include <vector>
#include <map>

using namespace std;


map<string, int> m;

int cnt = 0;
char arr[5] = {'A', 'E', 'I', 'O', 'U'};

void solve(int depth, string str) {
    if (str.length() > 0) {
        m[str] = ++cnt;
    }
    
    if (depth == 5) {
        return;
    }
    
    for (int i = 0; i < 5; i++) {
        solve(depth + 1, str + arr[i]);
    }
}

int solution(string word) {
    solve(0, "");
    int answer = m[word];
    return answer;
}