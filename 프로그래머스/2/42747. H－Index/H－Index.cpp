#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    
    for (int h = citations[0]; h > 0; h--) {
        int cnt = 0;
        while (cnt < citations.size() && citations[cnt] >= h) {
            cnt++;
        }
        if (cnt >= h) {
            return h;
        }
    }
    
    return 0;
}