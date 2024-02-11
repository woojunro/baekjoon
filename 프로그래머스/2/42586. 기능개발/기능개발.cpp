#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> etas;
    
    for (int i = 0; i < progresses.size(); i++) {
        int eta = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i] != 0) {
            eta++;
        }
        etas.push_back(eta);
    }
    
    vector<int> answer;
    
    int i = 1, cnt = 1, day = etas[0];
    while (i < etas.size()) {
        if (etas[i] <= day) {
            cnt++;
        } else {
            answer.push_back(cnt);
            cnt = 1;
            day = etas[i];
        }
        i++;
    }
    answer.push_back(cnt);
    
    return answer;
}