#include <iostream>

int heap[100001];
int size = 0;

void swap(int i, int j) {
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void insert(int x) {
    heap[++size] = x;
    
    int i = size;
    while (i > 1 && heap[i] < heap[i / 2]) {
        swap(i, i / 2);
        i /= 2;
    }
}

int pop() {
    if (size == 0) {
        return 0;
    }
    
    int ret = heap[1];
    heap[1] = heap[size--];
    
    int i = 1;
    while (i * 2 <= size) {
        int child = i * 2;
        
        // compare children (if the right children exists)
        if (child + 1 <= size && heap[child + 1] < heap[child]) {
            child++;
        }
        
        if (heap[i] > heap[child]) {
            swap(i, child);
            i = child;
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