#include <iostream>

#define r 31
#define M 1234567891

using namespace std;

int main() {
    char c;
    int L, a;
    long long hash, coefficient;
    
    cin >> L;
    
    hash = 0;
    coefficient = 1;
    for (int i = 0; i < L; i++) {
        cin >> c;
        a = c - 96; // 'a' == 97
        
        hash += (a * coefficient) % M;
        hash %= M;
        coefficient = (coefficient * r) % M;
    }
    
    cout << hash << endl;
    
    return 0;
}