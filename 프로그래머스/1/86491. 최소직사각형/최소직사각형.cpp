#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int v = 0;
    int h = 0;
    
    for (vector<int> card: sizes) {
        if (card[0] < card[1]) {
            int tmp = card[0];
            card[0] = card[1];
            card[1] = tmp;
        }
        
        if (card[0] > v) v = card[0];
        if (card[1] > h) h = card[1];
    }
    
    int answer = v * h;
    return answer;
}