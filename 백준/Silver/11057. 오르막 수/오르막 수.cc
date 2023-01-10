#include <iostream>

#define MAX 1000
#define QUOTIENT 10007

int DP[MAX][10];

int main() {
	int N, sum;
	
	std::cin >> N;
	
	for (int i = 0; i < 10; i++) DP[0][i] = 1;
	
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				DP[i][j] += DP[i - 1][k];
				DP[i][j] %= QUOTIENT;
			}
		}
	}
	
	sum = 0;
	for (int i = 0; i < 10; i++) sum = (sum + DP[N - 1][i]) % QUOTIENT;
	std::cout << sum << std::endl;
	
	return 0;
}
