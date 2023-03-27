#include <iostream>
#include <vector>
#include <algorithm>

bool compare(std::pair<int, int> a, std::pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

int main() {
    int N, start, end;
    std::vector<std::pair<int, int>> meetings;
    
    std::cin >> N;
    
    for (int i = 0; i < N; i++) {
        std::cin >> start >> end;
        meetings.push_back(std::pair<int, int>(start, end));
    }
    
    std::sort(meetings.begin(), meetings.end(), compare);
    
    int count = 0;
    int end_time = 0;
    
    for (int i = 0; i < N; i++) {
        if (meetings[i].first >= end_time) {
            count++;
            end_time = meetings[i].second;
        }
    }
    
    std::cout << count << std::endl;
    
    return 0;
}