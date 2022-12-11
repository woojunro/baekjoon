#include <iostream>

int results[1001];

int main() {
	int n;
	
	std::cin >> n;
	
	for (int i = 1; i <= n; i++) {
		if (i == 1) results[i] = 1;
		else if (i == 2) results[i] = 3;
		else results[i] = (results[i - 1] + 2 * results[i - 2]) % 10007;
	}
	
	std::cout << results[n] << std::endl;
	
	return 0;
}
