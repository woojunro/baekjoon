#include <iostream>

#define MAX 1000

int DP[MAX + 1];
int A[MAX + 1];

int main() {
	int N, max;
	std::cin >> N;
	
	for (int i = 1; i <= N; i++) {
		std::cin >> A[i];
	}
	
	for (int i = 1; i <= N; i++) {
		max = -1;
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i] && DP[j] > max) {
				max = DP[j];
			}
		}
		DP[i] = A[i] + max;
	}
	
	max = -1;
	for (int i = 1; i <= N; i++) {
		if (DP[i] > max) {
			max = DP[i];
		}
	}
	
	std::cout << max << std::endl;
	
	return 0;
}
