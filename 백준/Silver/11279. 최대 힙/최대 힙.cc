#include <iostream>

int heap[100001];
int size = 0;

void swap(int a, int b) {
    int temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
}

void insert(int x) {
    heap[++size] = x;
    
    int loc = size;
    while (loc > 1 && heap[loc] > heap[loc / 2]) {
        swap(loc, loc / 2);
        loc /= 2;
    }
}

int pop() {
    if (size == 0) {
        return 0;
    }
    
    int ret = heap[1];
    heap[1] = heap[size--];
    
    int loc = 1;
    while (loc * 2 <= size) {
        int child = loc * 2;
        
        if (child + 1 <= size && heap[child + 1] > heap[child]) {
            child++;
        }
        
        if (heap[loc] < heap[child]) {
            swap(loc, child);
            loc = child;
        } else {
            break;
        }
    }
    
    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int N, num;
    std::cin >> N;
    
    for (int i = 0; i < N; i++) {
        std::cin >> num;
        
        if (num == 0) {
            std::cout << pop() << "\n";
        } else {
            insert(num);
        }
    }
    
    return 0;
}