#include <iostream>

#define MAX 90

long DP[MAX][2];

int main() {
	int N;
	
	std::cin >> N;
	
	DP[0][1] = 1;
	
	for (int i = 1; i < N; i++) {
		DP[i][0] = DP[i - 1][0] + DP[i - 1][1];
		DP[i][1] = DP[i - 1][0];
	}

	std::cout << DP[N - 1][0] + DP[N - 1][1] << std::endl;
	
	return 0;
}
