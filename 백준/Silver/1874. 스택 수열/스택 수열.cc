#include <iostream>
#include <stack>
#include <string>

#define MAX 100000

using namespace std;

int arr[MAX];
stack<int> s;
string str;

void stack_push(int x) {
    s.push(x);
    str.push_back('+');
    str.push_back('\n');
}

void stack_pop() {
    s.pop();
    str.push_back('-');
    str.push_back('\n');
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        if (i == arr[idx]) {
            stack_push(i);
            stack_pop();
            idx++;
        } else if (i < arr[idx]) {
            stack_push(i);
        } else {
            if (!s.empty() && s.top() == arr[idx]) {
                while (!s.empty() && s.top() == arr[idx]) {
                    stack_pop();
                    idx++;
                }
                stack_push(i);
            } else {
                cout << "NO" << "\n";
                return 0;
            }
        }
    }
    
    while (!s.empty()) {
        if (s.top() == arr[idx]) {
            stack_pop();
            idx++;
        } else {
            cout << "NO" << "\n";
            return 0;
        }
    }
    
    cout << str;
    
    return 0;
}