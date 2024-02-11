#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    vector<string> v;
    unordered_map<string, int> m;
    
    for (vector<string> cloth: clothes) {
        if (m[cloth[1]] == 0) {
            v.push_back(cloth[1]);
        }
        m[cloth[1]]++;
    }
    
    int answer = 1;
    
    for (string s: v) {
        answer *= (m[s] + 1);
    }
    
    return --answer;
}