#include <iostream>

#define MAX 100000

int DP[2][MAX + 1];
int scores[2][MAX + 1];

int main() {
	int T, n;
	
	std::cin >> T;
	
	for (int i = 0; i < T; i++) {
		std::cin >> n;
		
		for (int j = 1; j <= n; j++) {
			std::cin >> scores[0][j];
		}
		
		for (int j = 1; j <= n; j++) {
			std::cin >> scores[1][j];
		}
		
		DP[0][1] = scores[0][1];
		DP[1][1] = scores[1][1];
		
		for (int j = 2; j <= n; j++) {
			if (DP[1][j - 1] > DP[1][j - 2]) {
				DP[0][j] = scores[0][j] + DP[1][j - 1];
			} else {
				DP[0][j] = scores[0][j] + DP[1][j - 2];
			}
			
			if (DP[0][j - 1] > DP[0][j - 2]) {
				DP[1][j] = scores[1][j] + DP[0][j - 1];
			} else {
				DP[1][j] = scores[1][j] + DP[0][j - 2];
			}
		}
		
		if (DP[0][n] > DP[1][n]) {
			std::cout << DP[0][n] << std::endl;
		} else {
			std::cout << DP[1][n] << std::endl;
		}
	}
	
	return 0;
}
