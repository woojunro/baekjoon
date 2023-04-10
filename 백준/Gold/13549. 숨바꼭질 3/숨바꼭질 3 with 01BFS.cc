#include <iostream>
#include <deque>

#define MAX 100001

using namespace std;

int dist[MAX + 1];
deque<int> dq;

int main() {
    int N, K;
    cin >> N >> K;
    
    for (int i = 0; i <= MAX; i++) dist[i] = -1;
    
    dist[N] = 0;
    dq.push_back(N);
    
    while (!dq.empty()) {
        int point = dq.front();
        dq.pop_front();
        
        if (point == K) break;
        
        if (2 * point <= MAX && dist[2 * point] < 0) {
            dist[2 * point] = dist[point];
            dq.push_front(2 * point);
        }
        
        if (point > 0 && dist[point - 1] < 0) {
            dist[point - 1] = dist[point] + 1;
            dq.push_back(point - 1);
        }
        
        if (point < MAX && dist[point + 1] < 0) {
            dist[point + 1] = dist[point] + 1;
            dq.push_back(point + 1);
        }
    }
    
    cout << dist[K] << endl;
    
    return 0;
}
