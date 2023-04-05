#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int arr[500000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + N);
    
    // mean
    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }
    cout << round(sum / N) + 0.0 << "\n";
    
    // median
    cout << arr[N / 2] << "\n";
    
    // mode
    int max_count = 0;
    vector<int> modes;
    int count = 0;
    for (int i = 0; i < N; i++) {
        count++;
        if (i < N - 1 && arr[i] == arr[i + 1]) {
            continue;
        } else {
            if (count == max_count) {
                modes.push_back(arr[i]);
            } else if (count > max_count) {
                max_count = count;
                modes.clear();
                modes.push_back(arr[i]);
            }
            count = 0;
        }
    }
    sort(modes.begin(), modes.end());
    cout << (modes.size() > 1 ? modes[1] : modes[0]) << "\n";
    
    // range
    cout << arr[N - 1] - arr[0] << "\n";
    
    return 0;
}