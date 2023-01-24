#include <iostream>

#define MAX 1000

int LEFT_INC[MAX + 1];
int RIGHT_INC[MAX + 1];
int A[MAX + 2];

int main() {
	int N, max;
	std::cin >> N;
	
	for (int i = 1; i <= N; i++) {
		std::cin >> A[i];
	}
	
	// LEFT_INC
	for (int i = 1; i <= N; i++) {
		max = -1;
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i] && LEFT_INC[j] > max) {
				max = LEFT_INC[j];
			}
		}
		LEFT_INC[i] = max + 1;
	}
	
	// RIGHT_INC
	for (int i = N; i >= 1; i--) {
		max = -1;
		for (int j = N + 1; j > i; j--) {
			if (A[j] < A[i] && RIGHT_INC[j] > max) {
				max = RIGHT_INC[j];
			}
		}
		RIGHT_INC[i] = max + 1;
	}
	
	max = -1;
	for (int i = 1; i <= N; i++) {
		if (LEFT_INC[i] + RIGHT_INC[i] > max) {
			max = LEFT_INC[i] + RIGHT_INC[i];
		}
	}
	
	std::cout << max - 1 << std::endl;
	
	return 0;
}
