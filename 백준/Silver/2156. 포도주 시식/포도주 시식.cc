#include <iostream>

#define MAX 10000

int DP[MAX + 3];
int wine[MAX + 1];

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n;
	
	std::cin >> n;
	
	for (int i = 1; i <= n; i++) {
		std::cin >> wine[i];
	}
	
	for (int i = 0; i < n; i++) {
		DP[i + 3] = max(DP[i + 1] + wine[i + 1], DP[i] + wine[i] + wine[i + 1]);
		DP[i + 3] = max(DP[i + 3], DP[i + 2]);
	}
	
	std::cout << DP[n + 2] << std::endl;
	
	return 0;
}
