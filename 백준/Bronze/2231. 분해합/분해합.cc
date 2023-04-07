#include <iostream>

using namespace std;

int sum(int x) {
    int a = x;
    int total = x;
    
    while (a != 0) {
        total += a % 10;
        a /= 10;
    }
    
    return total;
}

int main() {
    int N;
    cin >> N;
    
    int ret = 0;
    for (int i = 1; i <= N; i++) {
        if (sum(i) == N) {
            ret = i;
            break;
        }
    }
    
    cout << ret << endl;
    
    return 0;
}