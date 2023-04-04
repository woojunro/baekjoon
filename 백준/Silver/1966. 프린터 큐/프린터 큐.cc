#include <iostream>
#include <deque>
#include <queue>

int main() {
    int T, N, M, num, count;
    std::deque<int> d;
    std::priority_queue<int> pq;
    
    std::cin >> T;
    
    for (int i = 0; i < T; i++) {
        std::cin >> N >> M;
        
        while (!d.empty()) {
            d.pop_front();
        }
        
        while (!pq.empty()) {
            pq.pop();
        }
        
        for (int i = 0; i < N; i++) {
            std::cin >> num;
            pq.push(num);
            
            if (i == M) {
                num *= -1;
            }
            
            d.push_back(num);
        }
        
        count = 0;
        
        while (!d.empty()) {
            num = d.front() < 0 ? d.front() * -1 : d.front();
            
            if (num < pq.top()) {
                d.push_back(d.front());
                d.pop_front();
            } else {
                count++;
                
                if (d.front() < 0) {
                    break;
                } else {
                    pq.pop();
                    d.pop_front();
                }
            }
        }
        
        std::cout << count << "\n";
    }
    
    return 0;
}