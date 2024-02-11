#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> m;
vector<string> gs;
vector<int> ps;

bool cmp(int a, int b) {
    if (gs[a] == gs[b]) {
        if (ps[a] == ps[b]) {
            return a < b;
        }
        return ps[a] > ps[b];
    }
    return m[gs[a]] > m[gs[b]];
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    for (int i = 0; i < genres.size(); i++) {
        m[genres[i]] += plays[i];
    }
    
    vector<int> ids;
    for (int i = 0; i < genres.size(); i++) {
        ids.push_back(i);
    }
    gs = genres;
    ps = plays;
    sort(ids.begin(), ids.end(), cmp);
    
    vector<int> answer;
    
    string current_genre = "";
    int cnt = 0;
    for (int id: ids) {
        if (genres[id] == current_genre) {
            cnt++;
            if (cnt <= 2) {
                answer.push_back(id);
            }
        } else {
            current_genre = genres[id];
            cnt = 1;
            answer.push_back(id);
        }
    }
    
    return answer;
}