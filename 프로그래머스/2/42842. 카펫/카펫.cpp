#include <string>
#include <vector>

using namespace std;

// (w + h) * 2 - 4 = brown
// (w - 2) * (h - 2) = yellow

vector<int> solution(int brown, int yellow) {
    int s = (brown + 4) / 2;
    
    int w, h;
    
    for (h = 3; h * 2 <= s; h++) {
        w = s - h;
        if (w * h == brown + yellow) {
            break;
        }
    }
    
    vector<int> answer;
    
    answer.push_back(w);
    answer.push_back(h);
    
    return answer;
}