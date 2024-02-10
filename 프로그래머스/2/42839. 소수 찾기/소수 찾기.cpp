#include <string>
#include <vector>

#define MAX 10000000

using namespace std;

bool is_prime[MAX];

void check_prime() {
    for (int i = 2; i < MAX; i++) {
        is_prime[i] = true;
    }
    
    for (int i = 4; i < MAX; i += 2) {
        is_prime[i] = false;
    }
    
    for (int i = 3; i < MAX; i += 2) {
        for (int j = i * 2; j < MAX; j += i) {
            is_prime[j] = false;
        }
    }
}

void solve(string &numbers, vector<bool> &visited, vector<int> &perm, int r, int depth, int &ans) {
    if (depth == r) {
        int val = 0;
        int q = 1;
        for (int i = depth - 1; i >= 0; i--) {
            val += perm[i] * q;
            q *= 10;
        }
        if (is_prime[val]) {
            ans++;
            is_prime[val] = false;
        }
        return;
    }
    
    for (int i = 0; i < numbers.length(); i++) {
        if (visited[i]) {
            continue;
        }
        
        visited[i] = true;
        perm[depth] = numbers[i] - '0';
        
        solve(numbers, visited, perm, r, depth + 1, ans);
        
        visited[i] = false;
    }
}

int solution(string numbers) {
    check_prime();
    
    int answer = 0;
    
    for (int i = 1; i <= numbers.length(); i++) {
        vector<bool> visited(numbers.length(), false);
        vector<int> perm(i);
        solve(numbers, visited, perm, i, 0, answer);
    }
    
    return answer;
}