#include <iostream>

using namespace std;

int cube[25];

bool valid() {
    for (int i = 1; i <= 21; i += 4) {
        int color = cube[i];
        for (int j = 1; j <= 3; j++) {
            if (cube[i + j] != color) {
                return false;
            }
        }
    }
    return true;
}

void swap(int i, int j) {
    int tmp = cube[j];
    cube[j] = cube[i];
    cube[i] = tmp;
}

// 2 -> 6 -> 10 -> 23
void rotate_one() {
    swap(2, 6);
    swap(2, 10);
    swap(2, 23);
    swap(4, 8);
    swap(4, 12);
    swap(4, 21);
}

// 4 -> 14 -> 9 -> 19
void rotate_two() {
    swap(4, 14);
    swap(4, 9);
    swap(4, 19);
    swap(3, 16);
    swap(3, 10);
    swap(3, 17);
}

// 13 -> 5 -> 17 -> 21
void rotate_three() {
    swap(13, 5);
    swap(13, 17);
    swap(13, 21);
    swap(14, 6);
    swap(14, 18);
    swap(14, 22);
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= 24; i++) {
        cin >> cube[i];
    }

    rotate_one();
    if (valid()) {
        cout << 1;
        return 0;
    }
    rotate_one();
    rotate_one();
    if (valid()) {
        cout << 1;
        return 0;
    }
    rotate_one();

    rotate_two();
    if (valid()) {
        cout << 1;
        return 0;
    }
    rotate_two();
    rotate_two();
    if (valid()) {
        cout << 1;
        return 0;
    }
    rotate_two();

    rotate_three();
    if (valid()) {
        cout << 1;
        return 0;
    }
    rotate_three();
    rotate_three();
    if (valid()) {
        cout << 1;
        return 0;
    }

    cout << 0;

    return 0;
}