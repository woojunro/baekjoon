#include <iostream>

#define MAX 1000

int DP[MAX + 1];
int series[MAX + 1];

int main() {
	int N, max;
	std::cin >> N;
	
	for (int i = 1; i <= N; i++) {
		std::cin >> series[i];
	}
	
	for (int i = 1; i <= N; i++) {
		max = -1;
		for (int j = 0; j < i; j++) {
			if (series[j] < series[i] && DP[j] > max) {
				max = DP[j];
			}
		}
		DP[i] = max + 1;
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
