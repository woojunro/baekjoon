#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> m;
    
    for (string c: completion) {
        m[c]++;
    }
    
    for (string p: participant) {
        if (m[p] <= 0) {
            return p;
        }
        m[p]--;
    }
    
    return "";
}