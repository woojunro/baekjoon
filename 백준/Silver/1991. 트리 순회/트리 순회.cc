#include <iostream>
#include <string>

#define MAX 26

void preorder_traversal(int node, int children[][2], int size) {
    char output = node + 'A';
    std::cout << output;
    
    for (int i = 0; i < 2; i++) {
        if (children[node][i] != 0) {
            preorder_traversal(children[node][i], children, size);
        }
    }
}

void inorder_traversal(int node, int children[][2], int size) {
    char output = node + 'A';
    
    if (children[node][0] != 0) {
        inorder_traversal(children[node][0], children, size);
    }
    std::cout << output;
    if (children[node][1] != 0) {
        inorder_traversal(children[node][1], children, size);
    }
}

void postorder_traversal(int node, int children[][2], int size) {
    char output = node + 'A';
    
    if (children[node][0] != 0) {
        postorder_traversal(children[node][0], children, size);
    }
    if (children[node][1] != 0) {
        postorder_traversal(children[node][1], children, size);
    }
    std::cout << output;
}

int main() {
    int N;
    
    int children[MAX][2];
    bool visited[MAX];
    std::string line;
    std::cin >> N;
    
    for (int i = 0; i < N; i++) {
        std::getline(std::cin >> std::ws, line);
        int node = line[0] - 'A';
        
        // Left child
        if (line[2] != '.') {
            children[node][0] = line[2] - 'A';
        } else {
            children[node][0] = 0;
        }
        
        // Right child
        if (line[4] != '.') {
            children[node][1] = line[4] - 'A';
        } else {
            children[node][1] = 0;
        }
    }
    
    preorder_traversal(0, children, N);
    std::cout << "\n";
    
    inorder_traversal(0, children, N);
    std::cout << "\n";
    
    postorder_traversal(0, children, N);
    std::cout << "\n";
    
    return 0;
}