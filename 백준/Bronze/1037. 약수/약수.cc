#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int nums[50];
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    
    sort(nums, nums + N);
    
    cout << nums[0] * nums[N - 1] << endl;
    
    return 0;
}