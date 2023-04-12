#include <iostream>

#define MAX 100000

using namespace std;

int inorder[MAX];
int postorder[MAX];

void preorder(int in_s, int in_e, int post_s, int post_e) {
    cout << postorder[post_e] << " ";
    
    for (int i = in_s; i <= in_e; i++) {
        if (inorder[i] == postorder[post_e]) {
            int left_count = i - in_s;
            if (left_count > 0) preorder(in_s, i - 1, post_s, post_s + left_count - 1);
            
            int right_count = in_e - i;
            if (right_count > 0) preorder(i + 1, in_e, post_e - right_count, post_e - 1);
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) cin >> inorder[i];
    for (int i = 0; i < n; i++) cin >> postorder[i];
    
    preorder(0, n - 1, 0, n - 1);
    
    return 0;
}