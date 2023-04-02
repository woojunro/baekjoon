#include <iostream>
#include <algorithm>

void permutation(bool visited[], int data[], int N, int perm[], int M, int prefix) {
    if (prefix == M) {
        for (int i = 0; i < M; i++) {
            std::cout << perm[i] << " ";
        }
        std::cout << "\n";
    } else {
        for (int i = 0; i < N; i++) {
            if (visited[i]) {
                continue;
            }
            
            perm[prefix] = data[i];
            visited[i] = true;
            permutation(visited, data, N, perm, M, prefix + 1);
            visited[i] = false;
        }
    }
}

int main() {
    int data[8], perm[8];
    bool visited[8] = {0};
    int N, M;
    std::cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        std::cin >> data[i];
    }
    
    std::sort(data, data + N);
    
    permutation(visited, data, N, perm, M, 0);
    
    return 0;
}