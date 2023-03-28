#include <iostream>
#include <set>
#include <map>

int points[1000000];
std::set<int> unique_points;
std::map<int, int> compressed;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int N;
    std::cin >> N;
    
    for (int i = 0; i < N; i++) {
        std::cin >> points[i];
    }
    
    for (int i = 0; i < N; i++) {
        unique_points.insert(points[i]);
    }
    
    std::set<int>::iterator iter;
    int comp = 0;
    for (iter = unique_points.begin(); iter != unique_points.end(); iter++) {
        compressed.insert(std::pair<int, int>(*iter, comp++));
    }
    unique_points.clear();
    
    for (int i = 0; i < N; i++) {
        if (i != 0) {
            std::cout << " ";
        }
        
        std::map<int, int>::iterator iter2;
        iter2 = compressed.find(points[i]);
        std::cout << iter2->second;
    }
    
    std::cout << std::endl;
    
    return 0;
}