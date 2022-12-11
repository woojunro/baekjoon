#include <iostream>

#define MAX 100
#define QUOTIENT 1000000000

int DP[MAX][10];

int main() {
	int N, sum;
	
	std::cin >> N;
	
	for (int i = 1; i < 10; i++) DP[0][i] = 1;
	
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) DP[i][j] = DP[i - 1][1];
			else if (j == 9) DP[i][j] = DP[i - 1][8];
			else DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % QUOTIENT;
		}	
	}
	
	sum = 0;
	for (int i = 0; i < 10; i++) sum = (sum + DP[N - 1][i]) % QUOTIENT;
	std::cout << sum << std::endl;
	
	return 0;
}
